class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++){
            char c = s[i];
            if(c=='[') count++;
            else if(c==']' && count>0) count--;
        }
        return (count+1)/2;
    }
};