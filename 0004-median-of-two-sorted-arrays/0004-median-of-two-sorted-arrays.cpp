class Solution {
public:
    double getValue1(vector<int>&arr1, vector<int>&arr2, int n, int m, int targetIdx){
        int i = 0, j = 0;
        int currentIdx = 0;
        while(i<n && j<m){
            int val;
            if(arr1[i]<arr2[j]) {
                currentIdx++;
                if(currentIdx > targetIdx){
                    return double(arr1[i]);
                }
                i++;
            }
            else {
                currentIdx++;
                if(currentIdx > targetIdx){
                    return double(arr2[j]);
                }
                j++;
            }            
        }
        while(i<n){
            currentIdx++;
            if(currentIdx > targetIdx){
                return double(arr1[i]);
            }
            i++;
        }
        while(j<m){
            currentIdx++;
            if(currentIdx > targetIdx){
                return double(arr2[j]);
            }
            j++;
        }
        return 0.0;
    }

    pair<double, double>getValue2(vector<int>&arr1, vector<int>&arr2, int n, int m, int targetIdx){
        int i = 0, j = 0;
        int currentIdx = 0;
        double first=-1.0,second=-1.0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]) {
                currentIdx++;
                if(currentIdx > targetIdx-1 && first==-1.0){
                    first = double(arr1[i]);
                }
                else if(currentIdx > targetIdx && second==-1.0){
                    second = double(arr1[i]);
                    break;
                }
                i++;
            }
            else {
                currentIdx++;
                if(currentIdx > targetIdx-1 && first==-1.0){
                    first = double(arr2[j]);
                }
                else if(currentIdx > targetIdx && second==-1.0){
                    second = double(arr2[j]);
                    break;
                }
                j++;
            }            
        }
        while(i<n){
            currentIdx++;
            if(currentIdx > targetIdx-1 && first==-1.0){
                first = double(arr1[i]);
            }
            else if(currentIdx > targetIdx && second==-1.0){
                second = double(arr1[i]);
                break;
            }
            i++;
        }
        while(j<m){
            currentIdx++;
            if(currentIdx > targetIdx-1 && first==-1.0){
                first = double(arr2[j]);
            }
            else if(currentIdx > targetIdx && second==-1.0){
                second = double(arr2[j]);                
                break;
            }
            j++;
        }        
        return {first, second};
    }

    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        // brute -- store in 3rd array (sort) and find
        // better -- don't store we just need the middle 1(odd), 2(even) elements
        int n = arr1.size();
        int m = arr2.size();
        int len = n+m;
        if(len%2==1){
            return getValue1(arr1, arr2, n, m, len/2);            
        }
        else{
            auto p = getValue2(arr1, arr2, n, m, len/2);
            cout<<p.first<<" "<<p.second<<endl;            
            double ans = (double(p.first)+double(p.second))/2.0;
            return ans;
        }
    }
};