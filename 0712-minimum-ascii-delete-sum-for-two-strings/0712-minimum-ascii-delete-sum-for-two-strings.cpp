class Solution {
    public:

    int help(int i, int j, string &s1, string &s2, int ans, vector<vector<int>>& dp){
        if(i>=s1.size()){
            int ans=0;
            for(int k=j;k<s2.size();k++){
                ans+=s2[k];
            }
            return ans;
        }
        if(j>=s2.size()){
            int ans=0;
            for(int k=i;k<s1.size();k++){
                ans+=s1[k];
            }
            return ans;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i]==s2[j]){
            return dp[i][j]=help(i+1,j+1,s1,s2,ans,dp);
        }
        return dp[i][j]=min(s1[i]+help(i+1,j,s1,s2,ans,dp), help(i,j+1,s1,s2,ans,dp)+s2[j]);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(0,0,s1,s2,0,dp);
    }
};