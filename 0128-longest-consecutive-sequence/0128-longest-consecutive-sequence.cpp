class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        int ans = 0;
        for(auto it:m){
            int x = it.first;
            if(m.find(x+1)!=m.end()){
                continue;
            }
            else{
                int temp = x-1;
                int count = 1;
                while(m.find(temp)!=m.end()){
                    count++;
                    temp = temp-1;
                }
                ans = max(ans, count);
            }
        }        
        return ans;
    }
};