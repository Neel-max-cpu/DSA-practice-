class Solution {
public:
    bool binarySearch(vector<int>&arr, int left, int right, int low, int high){
        while(left<=right){
            int mid = left+(right-left)/2;
            if(arr[mid]>=low && arr[mid]<=high) return true;
            else if(arr[mid]>high){                
                right = mid-1;
            }
            else left = mid+1;
        }

        return false;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        /* not any elements
        arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
        n = arr1 size and m = arr2 size
        all abs(arr[0]-arr2[0...m-1])>d (count = 1)
        all abs(arr[1]-arr2[0...m-1])>d (count = 2)
        but abs(arr[2]-arr2[0....m-1] there are some values which are <=d)
        so return count 2;
        */

        int count = 0;
        // brute
        /*
        for(int i=0; i<arr1.size(); i++){
            bool flag = true;
            for(int j=0; j<arr2.size(); j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
        */

        // optimal using binary search --
        // for an element x and an element y for abs(x-y)<=d then y would be y=x(+-)d
        // so y = x-d and y = x+d 
        sort(arr2.begin(), arr2.end());
        for(int i=0; i<arr1.size(); i++){
            int left = arr1[i]-d;
            int right = arr1[i]+d;
            if(!binarySearch(arr2, 0, arr2.size()-1, left, right)){
                count++;
            }
        }
        return count;
    }
};