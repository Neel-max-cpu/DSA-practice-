class Solution {
public:
    void merge(vector<int>&arr, int low, int mid, int high){
        int l = low, r = mid+1;
        vector<int>temp;        
        while(l<=mid && r<=high){            
            if(arr[l]<=arr[r]){
                temp.push_back(arr[l]);
                l++;                
            }
            else {
                temp.push_back(arr[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(arr[l++]);
        }
        while(r<=high) temp.push_back(arr[r++]);
        for(int i=0; i<temp.size(); i++){
            arr[low+i] = temp[i];
        }        
    }

    int countPairs(vector<int>&arr, int low, int mid, int high){
        int count = 0;
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && arr[i] > (long long)2*(long long)arr[j]){
                j++;
            }
            count += (j-(mid+1));   
            //since already did j++ so mid+1 = 0th ele of the right arr and j is curr index
        }
        return count;
    }

    int mergeSort(vector<int>&arr, int low, int high){
        if(low>=high) return 0;
        int mid = low + (high-low)/2;
        int ans1 = mergeSort(arr, low, mid);
        int ans2 = mergeSort(arr, mid+1, high);
        // since both the parts are sorted
        int ans3 = countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return ans1+ans2+ans3;
    }

    int reversePairs(vector<int>& nums) {
        // merge sort
        int n = nums.size();
        int count = mergeSort(nums, 0, n-1);
        return count;
    }
};