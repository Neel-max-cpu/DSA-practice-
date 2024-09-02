class Solution {
public:
    set<string> find_per(string s){
        set<string>ans;
        sort(s.begin(), s.end());

        do{
            ans.insert(s);
        }while(next_permutation(s.begin(), s.end()));
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        // METHOD 2 ---
        unordered_map<string,vector<string>>m;
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.find(s)!=m.end()){
                m[s].push_back(strs[i]);
            }
            else m[s].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:m){
            vector<string>temp;
            for(auto x:it.second){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
        
        


        // mine METHOD1- doesnt pass all ---
        /*
        vector<vector<string>>ans;
        set<string>main;
        for(int i=0; i<n; i++){           
            if(main.find(strs[i])!=main.end()) continue;
            else{                                                                                                              
                vector<string>temp;
                string s = strs[i];
                if(s==""){
                    for(int j=0; j<n;j++){
                        if(strs[j]=="") {
                            temp.push_back(strs[j]);
                            main.insert(strs[j]);                                                                               
                        }
                    }
                    ans.push_back(temp);
                }
                else{
                    set<string>st = find_per(s); 

                    for(int j=0; j<n; j++){                                    
                        if(main.find(strs[j])==main.end()){
                            if(st.find(strs[j])!=st.end()){
                                temp.push_back(strs[j]);
                                main.insert(strs[j]);                                                                               
                            }                    
                        }
                    }            
                    ans.push_back(temp);
                }
            }
        }
        return ans;
        */
    }
};