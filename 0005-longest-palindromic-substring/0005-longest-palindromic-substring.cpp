class Solution {
public:
    string longestPalindrome(string s) {
        string longest="";
        int len=0;
        int n=s.size();
        if(n==1){
            return s;
        }
        vector<vector<int>> dp(n,vector<int>(n+10,0));
        int x=0,y=0;

        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=2;
                x=i;
                y=i+1;
                len=2;
            }
        }

        for(int diff=2;diff<n;diff++){
            for(int i=0;(i+diff)<n;i++){
                if(s[i]==s[i+diff] && dp[i+1][i+diff-1]){
                    dp[i][i+diff]=dp[i+1][i+diff-1]+1;
                    if(diff+1>len){
                        x=i;
                        y=diff+i;
                        len=dp[i][i+diff];
                    }
                }
                
            }
        }
        longest=s.substr(x,y-x+1);
        if(longest.empty()){
            return longest=s[0];
        }
        else return longest;

    }
};