class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int carry = 0;
        int n = a.size();
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                if(a[i]==9){
                    a[i] = 0;
                    carry = 1;
                }
                else a[i]+=1;
            }
            else{
                if(a[i]==9){
                    if(carry==1) {
                        a[i] = 0; 
                        carry = 1;
                    }                    
                }
                else{
                    if(carry==1){
                        a[i]+=1;
                        carry = 0;
                    }                    
                }
            }
        }
        vector<int>v;
        if(carry==1) v.push_back(1);
        for(int i=0; i<n; i++){
            v.push_back(a[i]);
        }
        return v;
    }
};