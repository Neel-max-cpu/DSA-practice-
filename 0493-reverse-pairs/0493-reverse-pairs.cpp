class Solution {
public:
    void merge(vector<int>&arr, int start, int mid, int end){
        int left = start, right = mid+1;
        vector<int>temp;        
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{                
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid) temp.push_back(arr[left++]);
        while(right <= end) temp.push_back(arr[right++]);

        for(int i=0; i<temp.size(); i++){
            arr[start+i] = temp[i];
        }        
    }

    int countPairs(vector<int>&arr, int start, int mid, int end){
        int count = 0;
        int j = mid+1;
        /*
        Suppose we have a sorted left half [start..mid] and sorted right half [mid+1..end].
        Fix an element arr[i] in the left half.
        We want to count how many elements arr[j] in the right half satisfy: arr[i]>2∗arr[j]
        We start j = mid+1 and move forward while the condition is true.
        Why arr[mid+1 .. j-1]?
        When the while loop stops, j is the first index in the right half that does NOT satisfy the condition.
        All indices from mid+1 up to j-1 did satisfy the condition.
        So: number of valid pairs for this i=(j−1)−(mid+1)+1=j−(mid+1)
        */
        for(int i=start; i<=mid; i++){
            //for ele check how many it satisfies and j doesn't move back cause sorted
            // and number of element are : j-1 + (mid+1) +1
            while(j<=end && arr[i]> (long long) 2 * (long long)arr[j]){
                j++;
            }
            count += (j-(mid+1));
        }
        return count;
    }

    int mergeSort(vector<int>&arr, int start, int end){
        if(start>=end) return 0;
        int mid = start + (end-start)/2;
        int count1 = mergeSort(arr, start, mid);
        int count2 = mergeSort(arr, mid+1, end);
        //before merge count
        int count3 = countPairs(arr, start, mid, end);
        merge(arr, start, mid, end);
        return count1+count2+count3;
    }

    int reversePairs(vector<int>& arr) {
        int count = mergeSort(arr, 0, arr.size()-1);
        return count;
    }
};