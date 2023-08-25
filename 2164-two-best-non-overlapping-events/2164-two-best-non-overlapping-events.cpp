class Solution {
public:
    int solve(vector<vector<int>>& events, vector<int>& start, int i, int k, vector<vector<int>>& dp){
        if(i==events.size()||k==0){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }

        int nt=solve(events,start,i+1,k,dp);

        auto x=upper_bound(start.begin(),start.end(),events[i][1])-start.begin();
        int t=events[i][2]+solve(events, start, x,k-1,dp);
        return dp[i][k]=max(t,nt);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<vector<int>> dp(n+1, vector<int>(3,-1));

        vector<int> start;
        sort(events.begin(),events.end());

        for(int i=0;i<events.size();i++){
            start.push_back(events[i][0]);
        }

        return solve(events,start,0,2,dp);
    }
};