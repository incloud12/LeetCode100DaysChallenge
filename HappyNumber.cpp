class Solution {
public:
    bool isHappy(int n) {
        int ans;
    
     while(n!=1 && n!=4)
     {
        ans=0;
        while(n)
        {
            int j=n%10;
            n=n/10;
            ans=ans+(j*j);
           
        }
        n=ans;
     
     }  
     
        return n==1;
     
    
    }
};
