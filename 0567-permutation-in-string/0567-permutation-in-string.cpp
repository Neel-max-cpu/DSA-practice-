class Solution {
public:
    bool worstWay(string &s1, string &s2){
        unordered_map<char,int>m;
        for(auto it:s1){
            m[it]++;
        }        

        int n= s2.size();
        for(int i=0; i<s2.size();i++){
            char c = s2[i];
            if(m.find(c)!=m.end()){
                unordered_map<char,int>temp = m;
                int j = i+1;
                string t = "";
                t+=c;
                temp[c]--;
                while(j<n && temp.find(s2[j])!=temp.end() && temp[s2[j]]!=0){
                    t+=s2[j];
                    temp[s2[j]]--;
                    j++;
                }                
                if(t.size()==s1.size()) return true;
            }
        }
        return false;
    }

    bool checkInclusion(string s1, string s2) {

        // worst way --
        // return worstWay(s1, s2);


        // better --
        /*        
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
        */


        // optimal --
        if(s1.size()>s2.size()) return false;
        vector<int>count1(26,0);
        vector<int>count2(26,0);

        // only count the window size
        for(int i=0; i<s1.size(); i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }

        if(count1 == count2) return true;

        int j = 0;
        // the window always have a size of s1.size(), where i(right side) and j = left side of window
        // the loop runs since above its count1!=count2
        for(int i=s1.size(); i<s2.size(); i++){
            // remove from the left and increase from the right
            count2[s2[j]-'a']--;
            j++;
            count2[s2[i]-'a']++;

            // then check
            if(count1==count2) return true;
        }
        return false;
    }
};