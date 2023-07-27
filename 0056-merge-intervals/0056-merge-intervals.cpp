class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n=in.size();
        sort(in.begin(),in.end());
        vector<vector<int>> ans;
        if(n==0){
            return ans;
        }

        vector<int> curr;
        curr=in[0];

        for(int i=1;i<n;i++){
            if(in[i][0]<=curr[1]){
                curr[1]=max(curr[1],in[i][1]);
            }
            else{
                ans.push_back(curr);
                curr=in[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};