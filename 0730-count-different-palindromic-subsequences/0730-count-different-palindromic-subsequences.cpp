class Solution {
public:
const int MOD=1e9+7;
long long int dp[1005][1005];

    long long solve(int i, int j, string& s){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            int left=i+1;
            int right=j-1;

            while(left<=right && s[left]!=s[i]){
                left++;
            }
            while(left<=right && s[right]!=s[i]){
                right--;
            }

            if(left>right){
                return dp[i][j]=(2*solve(i+1,j-1,s)+2)%MOD;
            }
            else if(left==right){
                return dp[i][j]=(2*solve(i+1,j-1,s)+1)%MOD;
            }
            else{
                return dp[i][j]=(2*solve(i+1,j-1,s) - solve(left+1,right-1,s)+MOD)%MOD;
            }
        }
        else{
            return dp[i][j]=(solve(i+1,j,s)+solve(i,j-1,s)-solve(i+1,j-1,s)+MOD)%MOD;
        }

    }

    int countPalindromicSubsequences(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return solve(0,n-1,s);
    }
};