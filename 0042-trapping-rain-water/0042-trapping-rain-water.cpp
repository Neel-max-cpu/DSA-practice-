class Solution {
public:    
    int trap(vector<int>& arr) {
        int n = arr.size();      
        int ans = 0;  
        /*
        // wall greater on right
        vector<int>tallOnRight(n);
        tallOnRight[0] = arr[0];
        for(int i=1; i<n; i++){
            tallOnRight[i] = max(tallOnRight[i-1], arr[i]);
        }
        // wall greater on left
        vector<int>tallOnLeft(n);
        tallOnLeft[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){            
            tallOnLeft[i] = max(tallOnLeft[i+1], arr[i]);
        }
        
        for(auto it:tallOnRight) cout<<it<<" ";
        cout<<endl;
        for(auto it:tallOnLeft) cout<<it<<" ";
                
        for(int i=0; i<n; i++){
            int waterLevel = min(tallOnRight[i], tallOnLeft[i]);
            int waterAboveMe = waterLevel - arr[i];
            ans += waterAboveMe;
        }
        */

        // optimal --
        int i = 0, j = n-1;
        int tallOnLeft =arr[i], tallOnRight = arr[j];
        while(i<j){
            if(tallOnLeft <= tallOnRight){
                i++;                
                int waterLevel = tallOnLeft;
                int waterAboveMe = waterLevel - arr[i];
                if(waterAboveMe>0) ans += waterAboveMe;;                
                tallOnLeft = max(tallOnLeft, arr[i]);
            }            
            else{
                j--;                
                int waterLevel = tallOnRight;
                int waterAboveMe = waterLevel - arr[j];
                if(waterAboveMe>0) ans += waterAboveMe;;                
                tallOnRight = max(tallOnRight, arr[j]);
            }
        }


        return ans;
    }
};