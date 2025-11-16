class Solution {
public:
    void find(vector<int>&arr, int i, set<vector<int>>&s, vector<int>&temp){
        if(i==arr.size()){
            if(s.find(temp)==s.end()){
                //if not found
                s.insert(temp);
            }
            return;
        }
        temp.push_back(arr[i]);
        find(arr, i+1, s, temp);
        temp.pop_back();
        find(arr, i+1, s, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {   
        sort(arr.begin(), arr.end());     
        set<vector<int>>s;
        vector<int>temp;
        find(arr, 0, s, temp);
        vector<vector<int>>ans(s.begin(), s.end());
        return ans;
    }
};