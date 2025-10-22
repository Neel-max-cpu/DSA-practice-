class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // start from the back since we don't need to shift elements from nums1 everytime a new element comes
        int i = m-1;    //last ele of num1
        int j = n-1;    //last ele of num2
        int k = n+m-1;  // last place in num1 where we will put the ele
        while(i>=0 && j>=0){
            //check which is larger
            if(nums1[i]>=nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};