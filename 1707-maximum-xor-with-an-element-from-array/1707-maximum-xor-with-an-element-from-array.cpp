struct Node {
    Node *links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node *get(int bit){
        return links[bit];
    }

    void put(int bit, Node *node){
        links[bit] = node;
    }
};


class Trie{
    private: Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node *node = root;
        for(int i=31; i>=0; i--){
            // if set or not
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node *node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();


        // brute --
        /*
        vector<int>ans;
        for(int i=0; i<m; i++){
            int maxXor = -1;
            for(int j=0; j<n; j++){
                if(nums[j]<=queries[i][1]){
                    maxXor = max(maxXor, nums[j]^queries[i][0]);
                }
            }
            ans.push_back(maxXor);
        }
        return ans;
        */

        // optimal ---
        sort(nums.begin(), nums.end());
        vector<pair<int,pair<int,int>>>arr;
        for(int i=0; i<m; i++){
            // <=mi(ai), xi, and index
            arr.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(arr.begin(), arr.end());
        
        Trie t;
        vector<int>ans(m, 0);
        int ind = 0;
        for(int i=0; i<m; i++){
            int ai = arr[i].first;
            int xi = arr[i].second.first;
            // query index
            int q_ind = arr[i].second.second;
            
            while(ind<n && nums[ind]<=ai){
                t.insert(nums[ind]);
                ind++;
            }
            if(ind == 0) ans[q_ind] = -1;
            else ans[q_ind] = t.getMax(xi);
        }
        return ans;
    }
};