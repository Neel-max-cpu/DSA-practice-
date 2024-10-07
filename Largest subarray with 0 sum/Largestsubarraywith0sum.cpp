
/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Examples:

Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.
Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.




*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
  
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        /*
        int len = 0;
        int newi = 0, newj=0;
        for(int i=0; i<n; i++){
            int sum = arr[i];
            if(sum==0){
                if(len<1){
                    newi = i;
                    newj = i;
                    len =1;
                }
            }
            for(int j=i+1; j<n; j++){
                sum+=arr[j];
                if(sum==0){
                    if(len<j-i+1){
                        newi = i;
                        newj = j;
                        len = j-i+1;
                    }
                }
                
            }
        }
        // for(int i=newi; i<=newj; i++) cout<<arr[i]<<" ";
        // cout<<endl;
        return len;
        */
        
        // method 2 
        unordered_map<int,int>prefix;
        int newi = 0, newj = 0;
        int sum = 0, maxlen = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            
            if(sum == 0){
                maxlen = i+1;
                newi = 0;
                newj =i;
            }
            
            if(prefix.find(sum)!=prefix.end()){
                int len = i - prefix[sum];
                if(maxlen<len){
                    maxlen = len;
                    newi = prefix[sum]+1;
                    newj = i;
                }
            }
            else prefix[sum] = i;
        }
        
        // for(int i=newi; i<=newj; i++) cout<<arr[i]<<" ";
        // cout<<endl;
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends