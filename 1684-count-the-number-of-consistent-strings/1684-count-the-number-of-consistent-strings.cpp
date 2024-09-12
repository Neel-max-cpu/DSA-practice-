class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // brute --
        /*
        map<char,int>m;
        for(auto it:allowed) m[it]++;
        int count= 0;
        for(int i=0; i<words.size(); i++){
            string t = words[i];
            set<char>s;
            int f = 0;
            for(auto it:t){
                if(s.find(it)==s.end()){
                    // if not found
                    if(m.find(it)!=m.end()){
                        // if found in the map valid
                        s.insert(it);
                    }
                    // if not found in the map
                    else f = 1;
                }
            }
            if(f==0) count++; 
        }
        return count;
        */
        vector<int>v(26,0);
        for(auto it:allowed){
            int a = it-'a';
            v[a]++;
        }        

        int count = 0;
        for(int i=0;i<words.size(); i++){
            string t = words[i];
            int f = 0;
            for(auto it:t){
                int a = it-'a';                
                if(v[a]==0){
                    f=1;
                    break;
                }
            }
            if(f==0) count++;
        }
        return count;

    }
};