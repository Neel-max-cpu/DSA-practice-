class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {        
        long long ans = LLONG_MIN;
        long long prefixSum = 0;  
        unordered_map<int, long long>m;

        /*
        For a subarray from index j to index i, its sum is
        sum(j,i)=prefix[i]-prefix[j-1]
        i.e [-1,3,2,4,5] and if i want to find the subarray sum from 3(j=1), to 4(i=3) then
        prefix[i] = 8
        and prefix[j-1] = prefix[1-0] = prefix[0] = -1
        then sum = prefix[i]-prefix[j-1] = 8 - (-1) = 9

        same happens below for finding the sum of the subarray --
        prefixSum(sum till x-1) + x(current) = prefix till i
        m[x-k] or m[x+k] = prefix[j-1]
        */
        for(auto x:arr){
            /* since abs(first-second) = k
            then - second = first-k or second = first+k
            */
            if(m.find(x-k)!=m.end()){
                // prefixSum+x = entire sum till now 
                // m[x-k] - sum before the value
                ans = max(ans, prefixSum + x - m[x-k]);
            }
            if(m.find(x+k)!=m.end()){
                ans = max(ans, prefixSum + x - m[x+k]);
            }

            // Store the minimum prefix sum before this value
            if (m.find(x) == m.end()) {
                m[x] = prefixSum;
            } else {
                m[x] = min(m[x], prefixSum);
            }

            prefixSum += x;
        }
        return ans == LLONG_MIN ? 0 : ans;
        /*
        [-1,3,2,4,5], k = 3 dry run -- 
        
        -1: 
        -4(no), 3(no), 
        m[-1] = 0; prefix = 0-1=-1; ans = llongmin
        
        3: 
        0(no), 6(no), 
        m[3] = -1; prefix = -1+3=2; ans = llongmin
        
        2: 
        (-1) yes; ans = max(llongmin, 2+2-0) = 4, 5(no), 
        m[2]=2; prefix =2+2=4; ans = 4

        4:
        1(no),7(no)
        m[4]=4; prefix = 4+4=8, ans = 4

        5:
        2(yes); ans = max(4, 8+5-2) = max(4, 11)=11, 8(no),
        m[5]=8; prefix = 13; ans = 11

        */
    }
};