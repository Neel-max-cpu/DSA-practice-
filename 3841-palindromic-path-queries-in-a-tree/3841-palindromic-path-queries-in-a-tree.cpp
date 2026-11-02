class Solution {
public:
    bool hasPath(int start, int end, string &s, vector<vector<int>>&graph, string &temp){
        if(start == end){
            temp.push_back(s[start]);
            return true;
        }

        vector<bool>visited(graph.size(),false);
        vector<int> parent(graph.size(), -1);

        queue<int>q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();            
            if(curr==end) {
                // Reconstruct the path backwards
                int node = end;
                while (node != -1) {
                    temp.push_back(s[node]);
                    node = parent[node];
                }
                return true;
            }

            for(int neighbour: graph[curr]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = curr;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
    string getString(int start, int end, string &s, vector<vector<int>>&graph){
        string temp;
        if(hasPath(start, end, s, graph, temp)){
            return temp;
        }
        else return "";
    }
    bool isPalindrom(string &s){
        unordered_map<char,int>freq;
        for(char c:s){
            freq[c]++;
        }

        int oddCount = 0;
        for(auto it:freq){
            if(it.second%2!=0) oddCount++;
        }
                
        return oddCount<=1;
    }
    vector<bool>helper(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>>graph(n);
        for(int i=0; i<edges.size(); i++){
            int one = edges[i][0];
            int two = edges[i][1];
            graph[one].push_back(two);
            graph[two].push_back(one);
        }

        vector<bool>ans;
        for(int i=0; i<queries.size(); i++){
            string temp = queries[i];
            // cout<<temp<<": ";
            char c = temp[0];
            if(c=='u'){
                // update
                int j = 7;
                int idx = 0;
                while(temp[j]!=' '){
                    idx*=10;
                    idx+=temp[j]-'0';
                    j++;
                }                
                s[idx] = temp[j+1];
                
                // cout<<idx<<""<<s<<endl;                
            }
            else{
                //query                
                int start = 0;
                int j = 6;
                while(temp[j]!=' '){
                    start*=10;
                    start+=temp[j]-'0';
                    j++;
                }

                j=j+1;
                int end = 0;
                while(j<temp.size()){
                    end*=10;
                    end+=temp[j]-'0';
                    j++;
                }                
                string x = getString(start, end, s, graph);                
                
                // cout<<start<<" "<<end;
                // cout<<" "<<x<<endl;
                
                if(!x.empty()){
                    if(isPalindrom(x)){
                        ans.push_back(true);
                    }
                    else ans.push_back(false);
                }
                else ans.push_back(false);
            }
        }
        return ans;
    }    




    // optimal solu --
    vector<vector<int>> graph;
    vector<int> parent, depth, subtree, heavy, head, pos;
    int timer = 0;
    // Segment tree supporting range XOR and point updates
    struct SegTree {
        int n;
        vector<int> tree;
        SegTree(vector<int>& a) {
            n = a.size();
            tree.assign(4 * n, 0);
            build(1, 0, n - 1, a);
        }
        void build(int node, int l, int r, vector<int>& a) {
            if (l == r) {
                tree[node] = a[l];
                return;
            }

            int mid = l + (r - l) / 2;
            build(node * 2, l, mid, a);
            build(node * 2 + 1, mid + 1, r, a);
            tree[node] =
                tree[node * 2] ^ tree[node * 2 + 1];
        }
        void update(int node, int l, int r,
                    int idx, int value) {
            if (l == r) {
                tree[node] = value;
                return;
            }

            int mid = l + (r - l) / 2;

            if (idx <= mid)
                update(node * 2, l, mid, idx, value);
            else
                update(node * 2 + 1, mid + 1, r,
                       idx, value);

            tree[node] =
                tree[node * 2] ^ tree[node * 2 + 1];
        }
        int query(int node, int l, int r,
                  int ql, int qr) {
            if (ql <= l && r <= qr)
                return tree[node];

            if (r < ql || l > qr)
                return 0;

            int mid = l + (r - l) / 2;

            return query(node * 2, l, mid, ql, qr)
                 ^ query(node * 2 + 1, mid + 1, r,
                         ql, qr);
        }

        void update(int idx, int value) {
            update(1, 0, n - 1, idx, value);
        }

        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    };

    // First DFS: calculate subtree sizes and heavy children
    void dfs1(int root, int parentNode) {    
        parent[root] = parentNode;
        // all the node that are in the subtree of root including itself(so atleast 1 if leave node)
        subtree[root] = 1; 
        // currently no head(leaf node have no heavy/light child)
        heavy[root] = -1;

        for (int node : graph[root]) {
            // get the connected nodes
            if (node == parentNode) continue;

            depth[node] = depth[root] + 1;            
            dfs1(node, root); // root=node ,parent=root

            // update it
            subtree[root] += subtree[node];

            // in hld - heavy child is the child(node) with largest subtree, all other children are light children
            // -- so current node's subtree > assigned heavy node's subtree or heavy child is not initallized yet then update it
            if (heavy[root] == -1 ||
                subtree[node] > subtree[heavy[root]]) {
                heavy[root] = node;
            }
        }
    }

    // Second DFS: assign chain heads and array positions
    void dfs2(int node, int heavyNodeChainHead) {
        head[node] = heavyNodeChainHead;
        pos[node] = timer++;

        // If the current node has a heavy child, visit that child but KEEP THE SAME chain head.
        if (heavy[node] != -1)
            dfs2(heavy[node], heavyNodeChainHead);

        // Each light child starts a new chain
        for (int currNode : graph[node]) {
            // since undirected graphy we don't want to go back to their parent or heavy(since already processed)
            if (currNode == parent[node] || currNode == heavy[node])
                continue;

            // Because every light child starts a NEW heavy chain, and that child becomes the head of its own chain.
            dfs2(currNode, currNode);
        }
    }

    int charMask(char c) {
        return 1 << (c - 'a');
    }

    // XOR of all character masks on the path u -> v
    int pathQuery(int u, int v, SegTree& seg) {
        int result = 0;

        while (head[u] != head[v]) {
            // Always process the deeper chain first
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            result ^= seg.query(pos[head[u]], pos[u]);

            // Jump above the processed chain
            u = parent[head[u]];
        }

        // Both nodes are now on the same chain
        if (depth[u] > depth[v])
            swap(u, v);

        result ^= seg.query(pos[u], pos[v]);

        return result;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {

        // mine -- but tle
        // return helper(n, edges, s, queries);                

        // optimal ---         
        /* idea - 1) use bit mask to find the palindrom --
        at max we could have 1 odd character else at all time we need even character --
        *now how do we get that without counting freq and all = bitmask + xor
        int bit = 1 << (s[i] - 'a'); -- what this does is makes binary for that character
        eg for a it make 1, for b - 10 for c = 100 for d = 1000 and so on.... till z
        so if a string is abcd then its bitmask would be - 1111; now how would it help us - here xor comes to play since in xor same bit = off and opposite bit = 1
        so we can have mask = 0, and int bit = 1 << (s[i] - 'a'); and we can do mask ^=bit;
        eg - abba; i=0: mask=0,bit=1 then mask=1; i=1: mask=1,bit=10 then mask=11;
        i=2: mask=11, bit=10 then mask=01; i=3: mask=01,bit=1 then mask=0 (so at the end all are even so can be made palindrome)
        *at the end we just need to check whether the mask has at most 1 bitmask(not more than that)
        how can we do it?
        **(mask == 0 || (mask & mask-1)==0)
        if mask = 0(all are even), mask=4(100) then mask-1=3(11) then mask & mask-1 = 0 (eg aabbc)
        if mask = 12(1100) then mask-1=11(1011) then mask & mask-1 = 1000(8) so not possible


        2) to find the substring(we actually dont need to construct it -- HLD works - heavy light decomposition) **HLD is a technique that splits a tree into chains so that any path can be represented using only O(log n) contiguous ranges.
        */


        // optimal ---
        // 2d vector with row size n and empty column, create graph
        graph.assign(n, {});
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // tree's data         
        parent.assign(n, -1);   // Stores the parent of each node.
        depth.assign(n, 0);     // Stores the distance from the root.
        subtree.assign(n, 0);   // Stores the number of nodes in a node's subtree.
        heavy.assign(n, -1);    // Stores the heavy child of each node(heavy child = child having the largest subtree.)
        head.assign(n, 0);      // Stores the head (topmost node) of the heavy chain to which each node belongs
        pos.assign(n, 0);       // Stores the position of each node in the flattened array.
        timer = 0;

        // dfs1 -- calculate subtree size and heavy children -- root(0) and parent(-1 - doest have parent)
        dfs1(0, -1);
        // dfs2 -- node we are processing, and head of the current heavy node
        dfs2(0, 0);

        // Flattened array: character mask at each node's position
        vector<int> base(n);

        for (int u = 0; u < n; u++)
            base[pos[u]] = charMask(s[u]);

        SegTree seg(base);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                seg.update(pos[u], charMask(c));
            } else {
                int v;
                ss >> v;

                int mask = pathQuery(u, v, seg);

                // True if the mask has at most one set bit
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};