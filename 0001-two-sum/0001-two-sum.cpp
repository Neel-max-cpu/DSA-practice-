class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        //brute - o(n^2) - two loops
        // optimize o(nlogn) - sort then 2 pointers
        // best hashmap?
        int n = arr.size();
        unordered_map<int,int>m;
        for(int i = 0; i<n; i++){
            int x = arr[i];
            int left = target-x;
            if(m.find(left)!=m.end()){
                //if found
                return {i, m[left]};
            }
            else{
                //put the element in the map
                m[x] = i;
            }
        }
        return{-1,-1};
    }
};