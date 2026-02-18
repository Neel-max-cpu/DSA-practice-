class Solution {
public:
    double betterSol(int n, int m, int len, vector<int>&arr1, vector<int>&arr2){
        if(len%2==1){
            // odd mid ele
            int mid = len/2;            
            int i = 0, j=0;   
            int count=0;         
            while(i<n && j<m){                
                if(count==mid){
                    double ans = min(arr1[i], arr2[j]);
                    return ans;                    
                }
                if(arr1[i]<=arr2[j]) i++;
                else j++;
                count++;
            }

            while(i<n){
                if(count==mid){
                    return double(arr1[i]);
                }
                i++;
                count++;
            }

            while(j<m){
                if(count==mid){
                    return double(arr2[j]);
                }
                j++;
                count++;
            }
        }
        else{
            // even
            int mid = len/2;            
            int i = 0, j=0;   
            int count=0;         
            double first = 0.0;
            double second = 0.0;
            while(i<n && j<m){                
                if(count==mid-1){
                    vector<int>v(4,INT_MAX);
                    v[0] = arr1[i];
                    v[1] = arr2[j];
                    if(i+1<n){
                        v[2] = arr1[i+1];
                    }
                    if(j+1<m){
                        v[3] = arr2[j+1];
                    }
                    int one = INT_MAX, two = INT_MAX;
                    for(int i=0; i<4; i++){
                        if(v[i]<one){
                            two = one;
                            one = v[i];
                        }
                        else if(v[i]<two){
                            two = v[i];
                        }
                    }

                    first = one;
                    second = two;

                    double ans = (first+second)/(double)2;
                    return ans;
                }
                if(arr1[i]<=arr2[j]) i++;
                else j++;
                count++;
            }

            while(i<n){
                if(count==mid-1){
                    first = arr1[i];
                    second = arr1[i+1];
                    double ans = (first+second)/(double)2;
                    return ans;
                }
                i++;
                count++;
            }

            while(j<m){
                if(count==mid-1){
                    first = arr2[j];
                    second = arr2[j+1];
                    double ans = (first+second)/(double)2;
                    return ans;
                }
                j++;
                count++;
            }
        }
        return 0.0;
    }

    double betterSol2(int n, int m, int len, vector<int>&arr1, vector<int>&arr2){
        int median1 = 0, median2 = 0;
        int mid = len/2;
        int i = 0, j=0;
        for(int count = 0; count<=mid; count++){
            // each time when loop works update median2 since 
            // it would contain 2nd smallest ele; and always update median1
            median2 = median1;

            if(i<n && j<m){
                if(arr1[i] > arr2[j]){
                    median1 = arr2[j];
                    j++;
                }
                else {
                    median1 = arr1[i];
                    i++;
                }
            }
            else if(i<n){
                median1 = arr1[i];
                i++;
            }
            else if(j<m){
                median1 = arr2[j];
                j++;
            }
        }

        if(len%2==1){
            return double(median1);
        }
        else{
            double ans = (median1+median2)/(double)2;
            return ans;
        }
    }

    double optimal(vector<int>&arr1, vector<int>&arr2, int len){
        int n = arr1.size();
        int m = arr2.size();
        // take 0 elements; take all(n) elements
        int left = 0, right = n;
        while(left<=right){
            // mid represents how many eles we can take from arr1 into left partition
            int mid = left + (right-left)/2;
            /* 
            so left eles + right eles = n+m
            total elements on the leftSide = (n+m+1)/2; so if we take mid number of eles in 
            the left part from arr1 then we need to take leftSide-mid elems from arr2
            */
            int leftArr1 = INT_MIN, leftArr2 = INT_MIN;
            int rightArr1 = INT_MAX, rightArr2 = INT_MAX;
            // total elements in left 
            int totalInLeft = (len+1)/2;    // handle both odd/even 

            // partition index in arr2            
            int eleInArr2  = totalInLeft - mid;

            int indexArr1 = mid-1;
            int indexArr2 = eleInArr2-1;

            if(indexArr1>=0) leftArr1 = arr1[indexArr1];
            if(indexArr2>=0) leftArr2 = arr2[indexArr2];
            if(indexArr1<n) rightArr1 = arr1[indexArr1+1];
            if(indexArr2<m) rightArr2 = arr2[indexArr2+1];

            // boundary check ---
            if(leftArr1<=rightArr2 && leftArr2<=rightArr1){
                // true partition found
                
            }
            else if(leftArr1>rightArr2) left = mid+1;
            else if(leftArr2>rightArr1) right = mid-1;
        }
    }

    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int len = n+m;

        // o(m+n) -- like merging but doing directly
        //return betterSol(n,m,len, arr1, arr2);
        // return betterSol2(n,m,len, arr1, arr2);   

        // optimal -- o(log(m+n))
        // for tc take the smaller array ---
        if(n>m) return findMedianSortedArrays(arr2, arr1);
        return optimal(arr2, arr1, len);

    }
};