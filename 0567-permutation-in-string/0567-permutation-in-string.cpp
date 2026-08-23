class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m1;
        for(auto it:s1) m1[it]++;
        unordered_map<char,int>m2;
        for(auto it:s2) m2[it]++;

        int i =0;
        int n = s2.size();
        while(i<n){
            char c = s2[i];
            if(m1.find(c)!=m1.end()){
                // freq atleast should be equal or greater --
                if(m1[c]>m2[c]) return false;

                int j = i;
                unordered_map<char,int>temp1=m1;
                unordered_map<char,int>temp2=m2;
                while(j<n && temp1.find(s2[j])!=temp1.end()){
                    char x = s2[j];
                    temp2[x]--;
                    temp1[x]--;
                    if(temp1[x]==0) temp1.erase(x);
                    if(temp1.size()==0) return true;

                    j++;
                }
            }
            i++;
        }
        return false;
    }
};