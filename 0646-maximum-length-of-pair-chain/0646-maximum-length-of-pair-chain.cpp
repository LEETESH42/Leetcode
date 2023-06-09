class Solution {
public:
    static bool comp(vector<int>& p1, vector<int>& p2){
        return p1[1]<p2[1];
    }

    int solve(int i, int prev, vector<vector<int>>& pairs, int n, vector<vector<int>>& dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        int pick=-1e5;
        if(prev==-1 || pairs[prev][1]<pairs[i][0]){
            pick=1+solve(i+1,i,pairs,n,dp);
        }
        int notPick=solve(i+1,prev,pairs,n,dp);
        return dp[i][prev+1]=max(pick,notPick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),comp);

        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return solve(0,-1,pairs,n,dp);
        int c=1,s=0;

        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>pairs[s][1]){
                c++;
                s=i;
            }
        }
        return c;
    }
};