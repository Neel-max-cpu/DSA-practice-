class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        // better hashmap o(n) + o(n)
        //best --
        // since n/3 so there could be 2 ele(could be 1 too)
        int n = arr.size();
        int curr1 = 0, curr2 = 1; //to avoid conflict
        int count1=0, count2=0;
        for(auto it:arr){
            if(count1==0 && it!=curr2){
                curr1 = it;
                count1 = 1;
            }
            else if(count2 == 0 && it!=curr1){
                curr2 = it;
                count2 = 1;
            }
            else{
                if(it==curr1){
                    count1++;
                }
                else if(it==curr2){
                    count2++;
                }
                else{
                    count1--;
                    count2--;
                }
            }
        }   
        count1 = 0, count2=0;
        for(auto it:arr){
            if(it==curr1) count1++;
            else if(it==curr2) count2++;
        }
        vector<int>ans;
        if(count1>n/3) ans.push_back(curr1);
        if(count2>n/3) ans.push_back(curr2);
        return ans;
    }
};