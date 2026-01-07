class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>temp(n,0);
        stack<int>s;
                
        for(int i=nums2.size()-1; i>=0; i--){
            int curr = nums2[i];
            if(s.empty()) {
                temp[i] = -1;
                s.push(curr);
            }
            else{
                while(!s.empty() && s.top()<curr){
                    s.pop();
                }
                if(s.empty()) {
                    temp[i] = -1;
                }
                else{
                    temp[i] = s.top();
                }
                s.push(curr);
            }
        }

        cout<<"temp: ";
        for(auto it:temp){
            cout<<it<<" ";
        }
        cout<<endl;

        vector<int>ans(nums1.size(),0);
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    ans[i] = temp[j];
                }
            }
        }
        return ans;
    }
};