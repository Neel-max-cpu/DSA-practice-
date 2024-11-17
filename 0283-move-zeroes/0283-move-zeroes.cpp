class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        /*
        vector<int>temp;
        int count = 0;
        for(int i=0; i<n;i++){
            if(nums[i]!=0) temp.push_back(nums[i]);
            else count++;
        }
        for(int i=0; i<count; i++) temp.push_back(0);
        nums = temp;
        */


        /*
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]!=0){
                nums[i] = nums[j];
                i++;
                j++;                
            }
            else{
                j++;
            }
        }

        while(i<n){
            nums[i++] = 0;
        }
        */

        int j = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        if(j==-1) return;
        
        for(int i=j+1; i<n; i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }


    }
};