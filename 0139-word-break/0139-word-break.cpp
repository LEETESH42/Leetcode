class Solution {
public:
    bool solve(int i, string s, set<string>& se, vector<int>& dp){
        if(i==s.size()){
            return true;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        for(int j=i;j<s.size();j++){
            if(se.count(s.substr(i,j+1-i)) && solve(j+1,s,se,dp)){
                dp[i]=true;
                return true;
            }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& w) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        set<string> se(w.begin(),w.end());
        return solve(0,s,se,dp);
    }
};