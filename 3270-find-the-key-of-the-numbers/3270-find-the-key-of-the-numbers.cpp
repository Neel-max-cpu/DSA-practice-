class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
       vector<int>v1(4,0);
       vector<int>v2(4,0);
       vector<int>v3(4,0);

        int i = 3;
        while(num1>0){
            v1[i] = num1%10;
            num1/=10;
            i--;
        }   
        i = 3;
        while(num2>0){
            v2[i] = num2%10;
            num2/=10;
            i--;
        }   
        i = 3;
        while(num3>0){
            v3[i] = num3%10;
            num3/=10;
            i--;
        }   


        int key = 0;
        for(int i=0; i<4; i++){
            int x= min({v1[i], v2[i], v3[i]});
            key = key*10 + x;
        }
        return key;


    }
};