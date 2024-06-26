class Solution {
public:
const int fact[7] = {1, 1, 2, 6, 24, 120, 720};
double total=0,match=0;
void dfs(vector<int>& balls,int p,int col1,int col2,int cnt1,int cnt2,double prm1,double prm2) 
{ 
    if (cnt1 == 0 && cnt2 == 0) {
        total+=prm1*prm2;
        match+=(col1==col2)*prm1*prm2;
    }
    else if (cnt1>=0 && cnt2>=0)
        for (int b1=0,b2=balls[p];b2>=0;++b1,--b2)
            dfs(balls,p+1,col1+(b1>0),col2+(b2>0),cnt1-b1,cnt2-b2,prm1/fact[b1],prm2/fact[b2]);
}
double factorial(int n) 
{ 
    return n < 3 ? n : n * factorial(n - 1); 
}
    double getProbability(vector<int>& balls) {
       auto n = accumulate(begin(balls), end(balls), 0);
    dfs(balls, 0, 0, 0, n / 2, n / 2, factorial(n / 2), factorial(n / 2));
    return match / total; 
    }
};
