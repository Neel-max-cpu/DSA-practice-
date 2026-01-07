class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int>s;
        unordered_map<int,int>m;
        for(int i=n-1; i>=0; i--){
            // till stack is not empty remove the ele which are smaller than nums2[i]
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }    

            // if stack is empty
            if(s.empty()){
                m[nums2[i]] = -1;            
            }
            else {
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        vector<int>ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};