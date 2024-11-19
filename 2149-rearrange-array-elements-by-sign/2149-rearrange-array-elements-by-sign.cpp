class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int>v(n);
        int j = 0;
        int k = 1;
        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                v[j]=arr[i];
                j+=2;
            }
            else{
                v[k]=arr[i];
                k+=2;
            }
        }        
        return v;
    }
};