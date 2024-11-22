class Solution {
public:

    vector<int>generateRow(int row){
        int ans = 1;
        vector<int>v;
        v.push_back(1);
        for(int i=1; i<row; i++){
            ans = ans*(row-i);
            ans = ans/i;
            v.push_back(ans);
        }
        return v;
    }
    vector<int>generate(vector<int>&temp, int row){
        vector<int>ans(row);
        ans[0] = 1;
        for(int i=1; i<row-1; i++){
            ans[i] = temp[i-1]+temp[i];
        }
        ans[row-1] = 1;
        return ans;
    }

    vector<vector<int>> generate(int n) {
        /*
        vector<vector<int>>v1;
        for(int i=1; i<=n; i++){
            vector<int>temp = generateRow(i);
            v1.push_back(temp);
        }
        return v1;
        */
        if(n==1){            
            return {{1}};
        }
        else{
            vector<vector<int>>v;
            v.push_back({1});
            v.push_back({1,1});
            for(int i=2; i<n; i++){
                vector<int>temp=v[i-1];
                vector<int>arr = generate(temp, i+1);
                v.push_back(arr);
            }
            return v;            
        }
    }
};