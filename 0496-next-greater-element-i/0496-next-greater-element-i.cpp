class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>m;
        stack<int>s;
                
        for(int i=nums2.size()-1; i>=0; i--){
            int curr = nums2[i];
            if(s.empty()) {
                m[curr] = -1;
                s.push(curr);
            }
            else{
                while(!s.empty() && s.top()<curr){
                    s.pop();
                }
                if(s.empty()) {
                    m[curr] = -1;
                }
                else{
                    m[curr] = s.top();
                }
                s.push(curr);
            }
        }

        vector<int>ans(nums1.size(),0);
        for(int i=0; i<nums1.size(); i++){
            ans[i] = m[nums1[i]];
        }
        return ans;
    }
};