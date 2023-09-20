class Solution {
public:
    string mx(string a, string b){
        return a.size()>b.size()?a:b;
        return a>b?a:b;
    }

    string solve(vector<int> &cost, int tar,vector<string>& dp){
        if(tar==0){
            return "0";
        }
        if(dp[tar]!="-1"){
            return dp[tar];
        }

        string s="";

        for(int i=0;i<9;i++){
            if(cost[i]<=tar){
                string x=solve(cost,tar-cost[i], dp);
                if(x!=""){
                    s=mx(s,to_string(i+1)+x);
                }
            }
        }
        return dp[tar]=s;
    }

    string largestNumber(vector<int>& cost, int tar) {
        vector<string> dp(tar+1,"-1");
        string ans=solve(cost,tar,dp);
        if(ans==""){
            return "0";
        }
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};