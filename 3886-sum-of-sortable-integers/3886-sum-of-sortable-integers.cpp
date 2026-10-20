class Solution {
public:

    vector<int>getDivisors(int n){        
        vector<int> count;
        vector<int> larger;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count.push_back(i);
                // Why i != n / i? It prevents duplicate divisors when n is a perfect square, such as n = 16, where 4 would otherwise be added twice.
                if (i != n / i) {
                    larger.push_back(n / i);
                }
            }
        }
        reverse(larger.begin(), larger.end());
        count.insert(count.end(), larger.begin(), larger.end());
        return count;
    }

    vector<int> getStartIdx(vector<int>&temp, int x, int start, int end){
        // see only in that window where it is ---
        vector<int>v;
        for(int i=start; i<end; i++){
            if(temp[i]==x) v.push_back(i);
        }
        return v;
    }

    bool orderStaysSame(vector<int>&temp, vector<int>&arr, int startIdx, int endLimit, int mainStart, int len){
        int startLimit = mainStart;
        bool flag = true;     
        while(len>0){
            if (temp[startIdx] != arr[mainStart]) {
                return false;
            }           
            
            startIdx++;
            mainStart++;
            len--;
                    

            if (startIdx >= endLimit) {
                startIdx = startLimit;
            }
        }                
        return flag;
    }

    int helper(vector<int>&v, vector<int>&arr){
        int count = 0;
        vector<int>sorted = arr;
        sort(sorted.begin(), sorted.end());

        for(int i=0; i<v.size(); i++){
            vector<int>temp = arr;
            int k = v[i];
            int n = temp.size();
            bool valid = true;             
            for (int j = 0; j < n; j += k) {
                // see whether the order stays same for the particular window
                int startEle = sorted[j];
                vector<int> startIdxTemp = getStartIdx(temp,startEle, j, min(j+k, n));
                if(startIdxTemp.empty()){
                    valid = false;
                    break;
                }
                int len = min(j+k, n) - j;
                for(int start=0; start<startIdxTemp.size();start++){
                    valid = orderStaysSame(temp, sorted, startIdxTemp[start], min(j+k, n), j, len);
                    // if one passes then enough 
                    if(valid) break;                    
                }
                // if none passes then won't be happening
                if(!valid) break;
            }            
            if(valid){
                count+=k;
            }
        }
        return count;
    }


    // Checks whether arr[start ... start+k-1] is a
    // cyclic rotation of sorted[start ... start+k-1].
    bool isRotation(vector<int>& arr, vector<int>& sorted,int start, int k) {
        vector<int> lps(k, 0);

        // Build the KMP prefix table for the sorted segment.
        for (int i = 1, len = 0; i < k;) {
            if (sorted[start + i] == sorted[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search the sorted segment in the original block
        // repeated twice, without repeating its final element.
        for (int i = 0, j = 0; i < 2 * k - 1; i++) {
            int x = arr[start + (i % k)];
            while (j > 0 && x != sorted[start + j]) {
                j = lps[j - 1];
            }
            if (x == sorted[start + j]) {
                j++;
            }
            if (j == k) {
                return true;
            }
        }
        return false;
    }

    int sortableIntegers(vector<int>& arr) {
        int n = arr.size();
        // tle mine ---- 
        /*
        // there could be only 1 break point
        vector<int>divisors = getDivisors(n);      
        return helper(divisors, arr);
        */

        // optimized --- https://chatgpt.com/share/6ad7ab0c-7fbc-83ec-b1e5-0c5e92b65e9c
        // divisors stays the same
        vector<int>divisors = getDivisors(n);     

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int ans = 0;

        for (int k : divisors) {
            bool valid = true;
            for (int j = 0; j < n; j += k) {
                if (!isRotation(arr, sorted, j, k)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans += k;
            }
        }
        return ans;
 
        
    }
};