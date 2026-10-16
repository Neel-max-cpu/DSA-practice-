class Solution {
public:
    const long long MOD = 1e9+7;
    using ll = long long;
    struct Node {
        ll sum = 0;
        ll sumSq = 0;
        ll lazy = 0;
    };

    void apply(int node, int left, int right, vector<Node>&segmentTree, ll delta){
        ll length = right-left+1;

        /*
        [1, 2, 0, 0]
        We want to add 1 to every value, so the result is:
        [2, 3, 1, 1]

        before udpate - sum - 3 and sumsq = 5
        new sum = oldSum+length(since adding 1 always) = 3+4 = 7
        
        and sumsq = oldsumsq+2*oldsum+lenght = 5+2*3+4 = 15
        For each value x, increasing it by one changes its square by:
        (x+1)^2=x^2+2x+1 -- 
        x^2=oldsumSq
        x=oldSum
        1=lenght
        */
        ll oldSum = segmentTree[node].sum;

        segmentTree[node].sumSq = (segmentTree[node].sumSq +(2 * delta * oldSum + delta * delta * length)%MOD)%MOD;
        segmentTree[node].sum = (segmentTree[node].sum + delta * length)%MOD;


        //This records that the node has an update waiting to be passed to its children.
        segmentTree[node].lazy = (segmentTree[node].lazy + delta)%MOD;
    }

    void push(int node, int left, int right, vector<Node>&segmentTree){
        // If lazy == 0, there is nothing to pass down.
        // If left == right, this node is a leaf; it has no children.
        if(segmentTree[node].lazy == (ll)0 || left == right) return;

        int mid = left + (right-left)/2;    
        ll pending = segmentTree[node].lazy;


        // update left child    
        apply(node*2, left, mid,segmentTree, pending);
        // update right child
        apply(node*2+1, mid+1, right,segmentTree, pending);
 
        // clears the parent's pending update because both children have now received it.
        segmentTree[node].lazy = 0;
    }

    void update(int node, int left, int right, int qLeft, int qRight, vector<Node>&segmentTree){
        // no over lap -- current seg left,right is outside the requested range [qLeft , qRight] 
        if(qRight < left || qLeft > right) return;


        // The current segment is completely inside the requested range
        if(qLeft<=left && right<=qRight){
            // in apply send only 1
            apply(node, left, right, segmentTree, 1);
            return;
        }

        // Only part of the current segment overlaps
        push(node, left, right, segmentTree);

        int mid = left + (right-left)/2;

        update(2*node, left, mid, qLeft, qRight, segmentTree);
        update(2*node+1, mid+1, right, qLeft, qRight, segmentTree);

        // sum of parent's value = left+right
        segmentTree[node].sum =
            segmentTree[node * 2].sum + segmentTree[node * 2 + 1].sum;

        // sumSq of parent's value = left+right
        segmentTree[node].sumSq =
            segmentTree[node * 2].sumSq +
            segmentTree[node * 2 + 1].sumSq;
    }

    int sumCounts(vector<int>& arr) {
        // o(n^2 log n) -- set takes o(log n)
        // o(n^2) -- for unordered set
        /*
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            //set<int>st;
            unorderd_set<int>st;
            for(int j=i; j<arr.size();j++){
                st.insert(arr[j]);
                ans = ans + (st.size()*st.size());
            }
        }
        return ans;
        */

        // optimal -- using segment tree -- to learn see this
        // https://leetcode.com/problems/fruits-into-baskets-ii/description/
        vector<Node>segmentTree;   
        int n = arr.size();
        // initallize with empty Node - sum, sumsq, and lazy initallized with 0
        segmentTree.assign(4*n, Node{});
        
        // stores the most recent index of each element
        unordered_map<int,int>lastSeen;
        ll ans = 0;

        for(int right = 0; right<n; right++){
            int x = arr[right];
            int prev = -1;

            if(lastSeen.count(x)){
                prev = lastSeen[x];
            }

            /*
            This means: add one to the range [prev + 1, right].
            and if prev = -1 then 0 to right
            */
            update(1, 0, n - 1, prev + 1, right, segmentTree);

            // Sum of squared distinct counts for subarrays
            // ending at index i.
            ans = (ans + segmentTree[1].sumSq)%MOD;

            lastSeen[arr[right]] = right;
        }

        return (int)ans;

    }
};