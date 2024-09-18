class Solution {
public:
    string s = "";

    void helper(vector<int>&nums, int n){
        sort(nums.begin(), nums.end());
        do{
            string t = "";
            for(auto it:nums){
                t+=to_string(it);
                s = max(s, t);
            }
        }while(next_permutation(nums.begin(), nums.end()));
    }
    
    bool static func(const string &a, const string &b){
        return a+b>b+a;
    }

    string largestNumber(vector<int>& nums) {
        // brute -- n*n!
        /*
        int n = nums.size();
        helper(nums, n);
        return s;
        */
        string ans ="";
        vector<string>v;
        for(auto it:nums){
            v.push_back(to_string(it));
        }
        sort(v.begin(), v.end(), func);
        if(v[0]=="0") return "0";
        for(auto it:v){
            ans+=it;
        }
        return ans;
    }
};