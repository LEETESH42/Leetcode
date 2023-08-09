class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    int solve(vector<vector<int>>& env){
        int n=env.size();
        if(n==0){
            return 0;
        }

        vector<int> ans;
        ans.push_back(env[0][1]);

        for(int i=1;i<n;i++){
            if(env[i][1]>ans.back()){
                ans.push_back(env[i][1]);
            }
            else{
                int ind=lower_bound(ans.begin(), ans.end(), env[i][1])-ans.begin();
                ans[ind]=env[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),compare);
        int prev=-1;
        int curr=0;
        return solve(env);
    }
};