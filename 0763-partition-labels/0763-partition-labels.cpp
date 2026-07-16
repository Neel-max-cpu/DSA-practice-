class Solution {
public:
    vector<int> partitionLabels(string s) {    
        vector<int>last(26,-1);

        int n = s.size();
        for(int i=0; i<n; i++){
            int index = s[i]-'a';
            last[index] = i;
        }

        for(int i=0; i<26; i++){
            if(last[i]!=-1){
                char c = 'a'+i;
                cout<<c<<": "<<last[i]<<endl;
            }
        }
        /*  eg --
        "ababc"
        a: 2
        b: 3
        c: 4

        end = 2;
        loop from 1 to 4
        i = 1; currentEnd = 3; then end = max(2, 3) = 3; 1!=3 [end,i] (nothing)
        i = 2; currentEnd = 2; then end = max(3, 2) = 3; 2!=3 [end,i] (nothing)
        i = 3; currentEnd = 3; then end = max(3, 3) = 3; 3==3 [end,i] 
        (we can cut - push the len of the substring = i-start+1) and then start = i+1 => start =4
        i = 4; currentEnd = 3; then end = max(3, 4) = 4; 4==4 [end,i]
        (we can cut - push the len of the substring = i-start+1) and then start = i+1 => start =5

        */
        vector<int>ans;
        int end = -1;
        int start = 0;
        for(int i =0; i<n; i++){
            int index = s[i]-'a';
            int currentEnd = last[index];
            end = max(end, currentEnd);
            if(end == i){
                // we can cut the lenght
                int len = i-start+1;
                ans.push_back(len);
                start = i+1;
            }
            // else nothing changes
        }

        return ans;
    }
};