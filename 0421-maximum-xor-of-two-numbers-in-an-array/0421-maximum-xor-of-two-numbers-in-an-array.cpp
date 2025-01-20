struct Node{    
    Node *links[2];

    bool containsKey(int bit){
        // if bit is set or not
        return (links[bit]!=NULL);
    }

    Node *get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31; i>=0; i--){
            // if it is set or not
            /*
            lets take of 5digit bit(in code we are doing 32 bit) -- of 9(01001)
            then i from 4 to >=0
            then 
            9>>4 & 1 = 0 &1 = 0
            9>>3 & 1 = 0 &1 = 1
            9>>2 & 1 = 0 &1 = 0
            9>>1 & 1 = 0 &1 = 0
            9>>0 & 1 = 0 &1 = 1
            and the 0's/1's are bit, so we are checking that node contains 0/1 or not if not then create
            then move to that node
            */
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                // if doesn't contain
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node *node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            /*
            now a thing about xor, for oppsite bits it give 1 else 0 to max out we need to find the opp
            eg if num is 8(4 bit lets take then maximun number will be:-)
            8 = 1000(4bit)
            1000(8)
            0111(7)
            and = 1111(15) will be max for 4 bit since we took all the opposite bits
            */
            int bit = (num>>i)&1;
            // checking for the opposite 
            if(node->containsKey(1-bit)){
                // contains the opposite
                // so i can make this bit 1
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else{
                 // doesn't not contain so will stay 0
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        // brute --
        /*
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = nums[i]^nums[j];
                ans = max(ans, x);
            }
        }
        return ans;
        */

        // optimal ---
        /*
        Trie *t = new Trie();
        for(int i=0; i<n; i++){
            t->insert(nums[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, t->getMax(nums[i]));
        }
        return ans;
        */

        // or 
        Trie t;
        for(int i=0; i<n; i++){
            t.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, t.getMax(nums[i]));            
        }
        return ans;
    }
};