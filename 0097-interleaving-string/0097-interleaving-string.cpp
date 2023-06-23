class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i==s1.length() && j==s2.length() && k==s3.length()){
            return true;
        }

        bool x=false,y=false;

        if(i!=s1.length()){
            if(s1[i]==s3[k]){
                x=solve(s1,s2,s3,i+1,j,k+1,dp);
            } 
        }
        if(j!=s2.length()){
            if(s2[j]==s3[k]){
                y=solve(s1,s2,s3,i,j+1,k+1,dp);
            }
        }
        return dp[i][j]=x||y;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        int i=0,j=0,k=0;
        return solve(s1,s2,s3,0,0,0,dp);
    }
};