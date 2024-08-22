class Solution {
public: 
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int>v;
        v.push_back(1);
        int a= 1;
        // make a prefix array for all consecutive numbers
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]+1 == nums[i]){
                a++;
                v.push_back(a);
            }
            else{
                a=1;
                v.push_back(a);
            }
        }

        // Find in the prefix vector if the difference is equal to k hence proving the sub array has consecutive number
        // size will be n-k+1 size
        for(int i=0; i<=v.size()-k; i++){
            if((v[i+k-1] - v[i]+1) == k) ans.push_back(nums[i+k-1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
