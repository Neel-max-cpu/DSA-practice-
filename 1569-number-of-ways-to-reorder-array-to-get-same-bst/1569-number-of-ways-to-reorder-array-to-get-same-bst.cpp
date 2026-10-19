class Node{
    public:
    int value;
    Node*left,*right;
    Node(int value){
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:    
    void pushNode(Node*root, int n){
        if(root->left == NULL && root->right==NULL){
            // push it into it
            if(n>root->value){
                Node*val = new Node(n);
                root->right = val;
            }
            else{
                Node*val = new Node(n);
                root->left = val;
            }
            return;
        }
    
        if(root->value > n){
            if(root->left)
                pushNode(root->left, n);
            else{
                Node*val = new Node(n);
                root->left = val;
                return;
            }
        }
        else {
            if(root->right)
                pushNode(root->right, n);
            else{
                Node*val = new Node(n);
                root->right = val;
                return;
            }
        }
    }

    void print(Node*root, bool flag){
        Node*curr = root;
        queue<Node*>q;
        if(flag){
            // left sub tree
            if(root->left)
                q.push(root->left);
            // cout<<"left sub tree: ";
            while(!q.empty()){
                Node*curr = q.front();
                q.pop();
                // cout<<curr->value<<" ";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);                
            }
            cout<<endl;
        }
        else{
            // right sub tree
            if(root->right)
                q.push(root->right);
            // cout<<"right sub tree: ";
            while(!q.empty()){
                Node*curr = q.front();
                q.pop();
                // cout<<curr->value<<" ";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);  
            }
            cout<<endl;
        }
    }

    vector<Node*> getChoices(vector<Node*>&arr, int idx){
        int n = arr.size();
        vector<Node*>ans;
        for(int i=0; i<n; i++){
            if(i==idx){
                if(arr[i]->left){
                    ans.push_back(arr[i]->left);
                }
                if(arr[i]->right){
                    ans.push_back(arr[i]->right);
                }
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }


    void helper(set<vector<int>>&v, vector<int>&temp,vector<Node*>choices, int n){
        if(temp.size()==n){
            v.insert(temp);
            return;
        }

        /* eg tc 2 when we are 0th level our only choice is 3
        but when we are at 1st level the choices are 1,4
        now if we select 1 then choices at 2nd level become 4,2(previous left + immediate child of selected choice)
        similarly if 4 then choices are - 1,5
        */
        for(int i=0; i<choices.size(); i++){            
            temp.push_back(choices[i]->value);            
            vector<Node*>newChoices = getChoices(choices, i);
            helper(v, temp, newChoices, n);
            temp.pop_back();
        }
    }



    long long modPow(long long a, long long b) {
        /*
        Instead of multiplying a by itself b times, it reduces the number of operations to 
        O(log b)
        since at the end we are doing a^b
        eg if we want to do 3^13 instead of multiply 3, 13 times we do 
        13 = 8+4+1 in set bit of 2
        therefore, 3^13 = 3^8 + 3^4 + 3^1

        Iteration	b	b & 1	Action	                    result	    New a
        1	        13	  1	    Multiply result by 3	    3	        9
        2	        6	  0	    Skip multiplication	        3	        81
        3	        3	  1	    Multiply result by 81	    243	        6561
        4	        1	  1	    Multiply result by 6561	    1,594,323	43,046,721
        The final result is: 3^{13}=1,594,323
        */
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;
            // generates next power a^1, a^2, a^3,.....
            a = a * a % MOD;
            // halves b each time 
            b >>= 1;
        }

        return result;
    }
    long long ways(vector<int>& nums) {

        /*
        Dry run: [3,4,5,1,2]
        - Root: 3
        - Left subtree: [1,2], with 1 valid ordering.
        - Right subtree: [4,5], with 1 valid ordering.
        - Each subtree has 2 elements, so the number of ways to interleave them is:4c2

        now the combination would be 4c2
        then 4!/2!*(4-2)! = 4!/2!*2! = 6
        so total ordering excluding the original =6-1=5

        */
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        // left = 1,2
        // right = 4,5
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        // leftWays =1
        // rightWays =1
        long long leftWays = ways(left);
        long long rightWays = ways(right);

        long long interleave = 1;
        int L = left.size();
        int R = right.size();

        /*  
        That's what interleaving means: combining two sequences while preserving the relative order of elements within each sequence.
        Left/right interleaving	    Combined sequence after root
        1 2 4 5	                    [3,1,2,4,5]
        1 4 2 5	                    [3,1,4,2,5]
        1 4 5 2	                    [3,1,4,5,2]
        4 1 2 5	                    [3,4,1,2,5]
        4 1 5 2	                    [3,4,1,5,2]
        4 5 1 2	                    [3,4,5,1,2]

        Why is it 4c2?
        We have four positions to fill:
        _ _ _ _
        Two positions must be occupied by the left-subtree sequence [1,2]. The remaining two automatically belong to [4,5].
        
        More generally, if the left subtree contains L elements and the right subtree contains R elements, the number of interleavings is:
        (L+R)C(L)
        */

        // Calculate C(L + R, L) or c(L+R, R) since both same modulo MOD
        // using factorials and modular inverse
        for (int i = 1; i <= L + R; i++) {
            interleave = interleave * i % MOD;
        }

        long long factL = 1, factR = 1;

        for (int i = 1; i <= L; i++)
            factL = factL * i % MOD;

        for (int i = 1; i <= R; i++)
            factR = factR * i % MOD;

        long long denominator = factL * factR % MOD;

        // C(l+r, l) = (l+r)!/l!(l+r - l)! since nCr = n!/r!(n-r)!

        /* and here its interleave/denominator but our code has
        interleave currently stores (L+R)! % MOD.
        denominator stores L!*R! % MOD.
        so cant direclty divide so we need to calculate = a *b^(-1) % MOD
        a = interleave and b is denominator
        
        Where does modPow(denominator, MOD - 2) come from?
        modulus MOD=10^9+7 is prime.
        Fermat's Little Theorem tells us that, for a number d not divisible by this prime:
        d^{MOD-1} === 1 (mod MOD)
        then --        
        d^{MOD-2}* d === 1 (mod MOD)
        
        now it has the form of -- a * d === 1 (mod MOD) WHERE a = d^{MOD-2}        

        Rearranging gives:
        d^{-1} === d^{MOD-2} (mod MOD)     

        usefully cause lets say we calculate a/d (% MOD)   
        then we could calculate = a * d^(MOD-2) (% MOD)
        */

        interleave = interleave * modPow(denominator, MOD - 2) % MOD;

        /*
        Why multiply by leftWays and rightWays?
        This is the other important piece.

        Suppose the left subtree itself has 2 valid insertion orders, and the right subtree has 3 valid insertion orders.

        For each possible interleaving, we can independently choose one valid ordering of the left subtree and one valid ordering of the right subtree.

        So the total is:
        Total ways=(L+R) C (L) * leftWays * rightWays
        */

        return interleave * leftWays % MOD * rightWays % MOD;
    }    
    
    static const long long MOD = 1e9 + 7;
    int numOfWays(vector<int>& nums) {
        // create the binary Tree
        int n = nums.size();

        // mine ---
        /*
        Node*root = new Node(nums[0]);        
        for(int i=1; i<n; i++){
            // push into it
            pushNode(root, nums[i]);        
        }

        // print(root, true);
        // print(root, false);

        set<vector<int>>v;
        vector<int>temp;
        vector<Node*>choices;  
        choices.push_back(root);
        helper(v, temp, choices, n);

        // since all the valid also have the given nums so -1
        return v.size()-1;  
        */   

        // optimal -- 
        // so total ordering excluding the original =data-1
        return (ways(nums) - 1 + MOD) % MOD;   
    }
};