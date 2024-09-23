class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n < original.size() || m*n >original.size()) return {};
        vector<vector<int>>ans;
        int i =0;
        vector<int>temp;
        int count = 0;        
        for(; i<original.size(); i++){
            temp.push_back(original[i]);
            if(count==n-1){
                ans.push_back(temp);
                temp.clear();
                count = 0;                
            }
            else
                count++;
        }
        return ans;

    }
};