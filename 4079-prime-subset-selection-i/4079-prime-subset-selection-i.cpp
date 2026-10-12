class Solution {
public:
    
    bool isPrime(int n){
        // better would be seive of Sieve of Eratosthenes
         if (n < 2) return false;        
        for (int i = 2; i * i <= n; i++) {
            if(n%i==0) return false;
        }
        return true;
    }    
    
    vector<int> maxPrimes(int n, int s) {
        vector<int>arr;
        int sum = 0;
        for(int i=2;i<=n; i++){                        
            if(isPrime(i)){
                sum+=i;
                if(sum<=s){
                    arr.push_back(i);                        
                }
                else break;            
            }
        }        

        return arr;                
    }
};