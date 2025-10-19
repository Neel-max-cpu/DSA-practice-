class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(n==1){
            return ans;
        }
        ans.push_back({1,1});
        if(n==2){
            return ans;
        }
        n-=2;
        while(n>0){
            vector<int>temp;
            temp.push_back(1);
            vector<int>temp2 = ans.back();
            for(int i=0;i<temp2.size()-1; i++){
                int val = temp2[i]+temp2[i+1];
                temp.push_back(val);
            }
            temp.push_back(1);
            ans.push_back(temp);
            n--;
        }
        return ans;
    }
};