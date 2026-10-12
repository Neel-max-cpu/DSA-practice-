class Solution {
public:

    vector<int>getData(vector<int>&arr){
        vector<int>bit;
        for(auto n:arr){
            int i = 0;
            while(n>0){
                if(i>=bit.size()) bit.resize(i+1,0);

                if(n&1){
                    // if 1 is present
                    bit[i]++;
                }

                n>>=1;
                i++;
            }
        }

        return bit;
    }

    int getDeciaml(vector<int>&bit){
        int data = 0;
        for (int i = bit.size() - 1; i >= 0; i--) {
            if (bit[i] > 0) {
                // (1 << i) is a lightning-fast way to compute 2^i
                // basically 1*2^i and doing |(or) to join both data and 2^i
                data |= (1 << i); 
                bit[i]--; // Consume 1 count of this bit
            }
        }
        return data;
    }

    int maxSum(vector<int>& arr, int k) {
        vector<int>bit = getData(arr);
        int ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<k; i++){
            int decimal = getDeciaml(bit);  
            long long val = ((long long)decimal%mod * (long long)decimal%mod)%mod;
            ans = (ans + val)%mod;
        }
        return ans;
    }
};