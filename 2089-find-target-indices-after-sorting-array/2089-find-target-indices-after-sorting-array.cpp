class Solution {
public:
    vector<int> targetIndices(vector<int>& arr, int target) {
        vector<int>ans;
        // brute --- o(nlogn) + o(n) ~ o(nlogn)
        /*
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
        */

        // optimal -- o(n) -- count smaller than target then from that to targetCount(worst case whole array)
        int smallerThanTarget = 0;
        int targetCount = 0;
        for(int i=0; i<arr.size();i++){
            if(arr[i]==target) targetCount++;
            else if(arr[i]<target) smallerThanTarget++;
        }
        for(int i=smallerThanTarget; i<=smallerThanTarget+targetCount-1; i++){
            ans.push_back(i);
        }
        return ans;
    }
};