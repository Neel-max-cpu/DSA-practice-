class Solution {
public:

    vector<int>getData(vector<int>&arr){
        vector<int>bit;
        for(auto n:arr){
            int i = 0;
            while(n>0){
                // not initallizing the vector it a very larger array waste of space and time
                // so only incrasing if there is actually a value(1/0) there
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

    int getDecimal(vector<int>&bit){
        // we are getting the data from behind (in binary) and same time converting into decimal
        int data = 0;
        for (int i = bit.size() - 1; i >= 0; i--) {
            if (bit[i] > 0) {
                // (1 << i) is a lightning-fast way to compute 2^i
                // basically 1*2^i and doing |(or) to join both data and 2^i
                data |= (1 << i); 
                bit[i]--; // Consume 1 count of this bit

                /*
                eg - [1,2,2,1]
                i = 3: data = 0 | 1*2^3 = 0 | 8 = 8 (0000 | 1000)
                i = 2: data = 8 | 1*2^2 = 8 | 4 = 12 (1000 | 0100)
                i = 1: data = 12 | 1*2^1 = 12 | 2 = 14 (1100 | 0010)
                i = 0: data = 14 | 1*2^0 = 14 | 1 = 15 (1110 | 0001)

                eg [0,1,1,0]
                i = 3: 
                i = 2: data = 0 | 1*2^2 = 0 | 4 = 4 (0000 | 0100)
                i = 1: data = 4 | 1*2^1 = 4 | 2 = 6 (0100 | 0010)
                i = 0: 
                */
            }
        }
        return data;
    }

    int maxSum(vector<int>& arr, int k) {
        /*
        [2,6,5,8], 2=0010, 6=0110, 5=0101, 8=1000
        now what is set bit - 1,2,4,8,16,..... basically 2^i
        the vector returns us(for the above array) = [1,2,2,1]
        i.e. at i=0(2^0) there is 1 bit, at i=1(2^1) there are 2 bit, at i=2(2^2) there are 2 bit and finally at i=3(2^3) there is 1 bit
        this is how --
        2 = 0010 - [0,1]
        6 = 0110 - [0,2,1]
        5 = 0101 - [1,2,2]
        8 = 1000 - [1,2,2,1]

        now the solution involves taking the biggest - if we take 1 from (where bit[i]>0)
        then [1,2,2,1] for i = 0, we get - 1111 in decimal = 15 and bit = [0,1,1,0]
        then i = 1, we get - 0110 in decimal = 6 and bit = [0,0,0,0];
        and done since k=2
        so 15^2 + 6^2 = 261 which is our answer
        */
        vector<int>bit = getData(arr);
        int ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<k; i++){
            int decimal = getDecimal(bit);  
            long long val = ((long long)decimal%mod * (long long)decimal%mod)%mod;
            ans = (ans + val)%mod;
        }
        return ans;
    }
};