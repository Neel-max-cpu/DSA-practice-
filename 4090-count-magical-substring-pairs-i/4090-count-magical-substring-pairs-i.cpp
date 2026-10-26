class Solution {
public:
    int helper(string &s){
        int n = s.size();
        int count = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i; j<n-1; j++){
                string one = s.substr(i, j-i+1);
                unordered_set<char>st1(one.begin(), one.end());
                for(int k=j+1; k<n; k++){
                    string two = s.substr(j+1, k-j);
                    unordered_set<char>st2(two.begin(), two.end());
                    if(st1.size() == st2.size()) count++;
                }
            }
        }
        return count;
    }
    int helper2(string &s){
        int n = s.size();
        vector<vector<int>> distinct(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            vector<int> freq(256, 0);
            int cnt = 0;
            for (int j = i; j < n; j++) {
                /* if s[j] = 'a' then freq['a']++ == 0
                means --  freq['a'] == 0 then cnt++ then increament the val
                freq['a'] = 1, since left + operator

                -- since our consists o fonly lower case english char
                */
                // if (freq[(unsigned char)s[j]]++ == 0)
                if (freq[s[j] - 'a']++ == 0)
                    cnt++;    
                distinct[i][j] = cnt;
            }
        }

        int count = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i; j<n-1; j++){                
                for(int k=j+1; k<n; k++){
                    if(distinct[i][j] == distinct[j+1][k]) count++;
                }
            }
        }
        return count;       
    }

    int helper3(string &s){
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            vector<int> freq1(26, 0);
            int distinct1 = 0;
            for (int j = i; j < n - 1; j++) {
                if (freq1[s[j] - 'a']++ == 0) {
                    distinct1++;
                }
                vector<int> freq2(26, 0);
                int distinct2 = 0;
                for (int k = j + 1; k < n; k++) {
                    if (freq2[s[k] - 'a']++ == 0) {
                        distinct2++;
                    }
                    if (distinct1 == distinct2) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    int helper4(string &s){
        int n = s.size();
        vector<vector<int>>left(n, vector<int>(27,0));
        vector<vector<int>>right(n, vector<int>(27,0));

        // left[j][d] = number of substrings ending at j
        // having exactly d distinct characters.
        // Left side: every substring ending at j, with starting index i ranging from 0 to j.
        for (int j = 0; j < n; j++) {
            // end at j from 0 to n
            vector<int> freq(26, 0);
            int distinct = 0;
            for (int i = j; i >= 0; i--) {
                // i in the opposite because once we fix j, we want to find all substrings that end exactly at j.
                if (freq[s[i] - 'a']++ == 0) {
                    distinct++;
                }
                left[j][distinct]++;
                /*
                j moves forward because we are choosing each possible ending position.
                i moves backward because, for that ending position, we are extending the substring toward the beginning.
                freq and distinct are reset for each new j because we're starting a new group of substrings.
                */
            }
        }

        // right[i][d] = number of substrings starting at i
        // having exactly d distinct characters.
        //Right side: every substring starting at j+1(i here), with ending index k ranging from j+1 to n-1(here j).
        for (int i = n - 1; i >= 0; i--) {
            // i means the starting position of the right substring.(j+1)
            vector<int> freq(26, 0);
            int distinct = 0;
            for (int j = i; j < n; j++) {
                // and j = k(j+1) can go up to n
                if (freq[s[j] - 'a']++ == 0) {
                    distinct++;
                }
                right[i][distinct]++;
            }
        }
        /*  
        Suppose the left side has these distinct counts:
        [1, 2, 2, 3]
        And the right side has:
        [1, 2, 1, 3, 2]
        Distinct count	Left substrings	Right substrings
            1	                1	             2
            2	                2	             2
            3	                1	             1
        he number of matching pairs for this split is:
        1*2 + 2*2 + 1*1 = 7
        */
        long long ans = 0;
        // Split between j and j + 1.
        // here j is the split position
        for (int j = 0; j < n - 1; j++) {
            // For every split, we need to count how many left substrings and right substrings have equal distinct-character counts.
            // d represents the number of distinct characters.
            for (int d = 1; d <= 26; d++) {
                ans += 1LL * left[j][d] * right[j + 1][d];
            }
        }

        /*dry run -- aab
        left table --- (j=0)left[0][1]=1; (j=1)left[1][1]=2;
        (j=2)left[2][1] = 1 and left[2][2] = 2; 
        Ending index j	 d = 1	  d = 2	  d = 3
            0	           1	    0	    0
            1	           2	    0	    0
            2	           1	    2	    0
        
        right table --- (i=2)right[2][1]=1; (i=1)right[1][1]=1 and right[1][2]=1;
        (i=0)right[0][1]=2 and right[0][2]=1
        Starting index i	d = 1	d = 2	d = 3
            0	               2	  1	      0
            1	               1	  1	      0
            2	               1	  0	      0

        now split
        when j = 0: 
            d=1, left[0][1]*right[0+1][1] = 1*right[1][1] = 1*1 = 1
            d=2, left[0][2]*right[0+1][2] = 0*right[1][2] = 0*1 = 0
            total contribution = 1+0 = 1
        when j = 1:
            d=1, left[1][1]*right[2][1] = 2*1=2
            d=2, left[1][2]*right[2][2] = 0*0=2
            total contibution = 2+0 = 2
        
        final answer = 1+2 = 3

        */
        return ans;

    }
    int countMagicalPairs(string s) {        
        // tle --
        // return helper(s);        
        
        // better (tle still) --
        // return helper2(s);

        // more better similar to helper 2 but counting on the go--
        // return helper3(s);

        // optimized --
        return helper4(s);
    }
};