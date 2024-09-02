#include<unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            int x = target - nums[i];
            if(m.find(x)!=m.end()){
                ans.push_back(m[x]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return ans;




        /*
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]= i;
        }
        
        for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            if(m[temp]!=0){
                if(m[temp] == i) continue;
                else{
                    ans.push_back(i);
                    ans.push_back(m[temp]);
                    return ans;
                }
            }
        }
        return ans;
        */


        /*
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
                    
            }
        }
        return ans;
        */

        /*
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;
        
       for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            if(m[temp]!=0){
                if(m[temp] == i) continue;
                else{
                    ans.push_back(i);
                    ans.push_back(m[temp]);
                    break;
                }
            }
        }
        return ans;
        */

        /*
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return { -1, -1};
        */
        
        // 2pointer not working
        /*
        int i =0, j = nums.size()-1;
        while(i<=j){
            int x = nums[i] + nums[j];
            // cout<<x<<" "<<i<<" "<<j<<endl;
            if(x == target){
                // return {i, j};
                break;
            }
            else if(x>target){
                if(target>=0)
                    j--;
                else{
                    i++;
                }
            }
            else if(x<target) {

                if(target>=0)
                    i++;
                else{
                    j--;
                }
            }
        }
        return {i,j};
        // return {-1,-1};
        */
        
       
       
    }
};