class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // do binary search on smaller array
        if(n>m) return findMedianSortedArrays(nums2, nums1);

        int len = n+m;
        // length of the left half
        int left = (n+m+1)/2;

        int low = 0, high = n;
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = left-mid1;

            // calculate l1, l2, r1, and r2 initiallize with INT_MAX,MIN if they are not there
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            // if the index doens't exist so check boundary and put the elements in l/r
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];
            if(mid1-1>=0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(len%2==1) return max(l1, l2);
                else {
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;                   
                }
            }

            else if(l1>r2) high = mid1-1;
            else low = mid1+1;
        }
        return 0;
        
        

        // better ---
        /*
        int len = n+m;
        int ind2 = len/2;
        int ind1 = ind2-1;

        int i = 0, j =0;
        int count = 0;
        int mid1 = 0, mid2 = 0;
        while(i<n && j<m){                
            if(nums1[i]<nums2[j]){
                if(count==ind1) mid1 = nums1[i];
                if(count == ind2) mid2 = nums1[i];
                i++;
                count++;
            }
            else{
                if(count==ind1) mid1 = nums2[j];
                if(count==ind2) mid2 = nums2[j];
                j++;
                count++;
            }
        }

        while(i<n){
            if(count==ind1) mid1 = nums1[i];
            if(count==ind2) mid2 = nums1[i];
            i++;
            count++;
        }
        while(j<m){
            if(count==ind1) mid1 = nums2[j];
            if(count==ind2) mid2 = nums2[j];
            j++;
            count++;
        }


        if(len%2 == 1){
            return mid2;
        }
        else{
            return (double)((double)(mid1+mid2)/2.0);
        }
        */
     

        /*
        vector<int>v;
        int i=0, j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            v.push_back(nums1[i++]);
        }
        while(j<m){
            v.push_back(nums2[j++]);
        }
        double median = 0;
        int len = v.size();
        if(len%2==1) return (double)(1.00000 * v[len/2]);
        else{
            median = v[len/2] + v[len/2 -1];
            median = (1.00000)*median/2;
            return median;
        }
        */

        // brute force ---
        /*
        vector<int>v(n+m,0);
        int k = 0;
        for(int i=0; i<n; i++) v[k++] = nums1[i];
        for(int i=0; i<m; i++) v[k++] = nums2[i];
        double median = 0;
        int len = v.size();
        sort(v.begin(), v.end());
        if(len%2==1) return (double)(1.00000 * v[len/2]);
        else{
            median = v[len/2] + v[len/2 -1];
            median = (1.00000)*median/2;
            return median;
        }
        */
    }
};