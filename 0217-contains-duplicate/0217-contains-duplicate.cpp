class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        /*
        map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        for(auto it:m) {
            if(it.second>=2) return true;
        }
        return false;
        */

        // method 2 --
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            if(s.find(nums[i])!=s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};