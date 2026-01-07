class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            int x = arr[i];
            int left = target - x;
            if(m.find(left)!=m.end()){
                //found
                return {i,m[left]};
            }
            else{
                m[x] = i;
            }
        }
        return {-1,-1};
    }
};