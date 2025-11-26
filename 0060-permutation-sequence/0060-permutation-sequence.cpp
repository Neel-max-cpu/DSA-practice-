class Solution {
public:    
    int totalPermutation(int n){
        int ans = 1;
        for(int i=1; i<=n; i++){
            ans *= i;
        }
        return ans;
    }
    void findKth(string &temp, string &s, int n, int k){
        if(temp.size()==1){
            s+=temp[0];
            return;
        }

        // n-1 since chunks if n=4 then 1+{} ; 2+{} ; 3+{} ; 4+{}
        // here in {} we have 3 element option ans 3 element can have 3! = 6ways
        // so each chunks have 6 ways
        // so permutations of n-1
        // [total permutation can be optimized]
        int totalChunks = totalPermutation(n-1);        
        int index = k/totalChunks;
        
        //put the value in s
        s+= temp[index];
        // since temp is already sorted and for the next we don't need the temp[index]         
        // Deletes 1 char starting from index = index
        temp.erase(index, 1);
        // or - deletes a char at the pos index   
        // temp.erase(temp.begin() + index); 
                
        findKth(temp, s, n-1, k%totalChunks);
    }

    string getPermutation(int n, int k) {
        /*
        string s="";
        for(int i=1; i<=n; i++){
            s+=to_string(i);
        }
        k--;
        while(k--){
            next_permutation(s.begin(), s.end());
        }
        return s;
        */
        // 0th based so looking for k-1th based permutation ---
        /*
        string temp = "";
        for(int i=1; i<=n; i++){
            temp+=to_string(i);
        }  
        string s="";
        findKth(temp,s, n, k-1);
        return s;
        */

        // iterative way ---
        int totalChunks = 1;
        vector<int>number;
        for(int i=1; i<n; i++){
            totalChunks*=i;
            number.push_back(i);
        }
        number.push_back(n);
        string ans = "";
        k = k-1;
        while(true){
            if(number.size()==1){
                ans = ans + to_string(number[0]);
                break;
            }
            int index = k/totalChunks;
            ans = ans + to_string(number[index]);
            // erase at a particular index
            number.erase(number.begin()+index);            
            k = k%totalChunks;
            // optimized way to find the total permuation instead of calculation again
            totalChunks = totalChunks/number.size();
        }
        return ans;
    }
};