class Solution {
public:
int mod = 1e9+7;
int solve(int i,string& s,int &k,vector<int> &dp,int &n){
    if(i>=n)return 1;
    if(s[i]=='0')return 0;
    if(dp[i] != -1)return dp[i];
    long long int x = 0;
    int a = 0;
    for(int j = i; j< n; j++){
        x = x*10+(s[j]-'0');
        if(x<=k*1LL){
            a = (a+solve(j+1,s,k,dp,n))%mod;
        }else{
            break;
        }
    }
    return dp[i] = a;
}
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(0,s,k,dp,n);
    }
};