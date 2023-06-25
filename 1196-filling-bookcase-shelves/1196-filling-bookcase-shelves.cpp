class Solution {
public:
    int solve(vector<vector<int>>& books,vector<vector<int>>& dp,int sw,int curr,int csh,int csw){
        if(curr>=books.size()){
            return csh;
        }
        if(dp[curr][csw]!=-1){
            return dp[curr][csw];
        }

        int op1=INT_MAX;

        if(csw+books[curr][0]<=sw){
            op1=solve(books,dp,sw,curr+1,max(csh,books[curr][1]),csw+books[curr][0]);
        }
        int op2=solve(books,dp,sw,curr+1,books[curr][1],books[curr][0])+csh;
        return dp[curr][csw]=min(op1,op2);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(1003, vector<int>(1003,-1));
        return solve(books,dp,shelfWidth,0,0,0);
    }
};