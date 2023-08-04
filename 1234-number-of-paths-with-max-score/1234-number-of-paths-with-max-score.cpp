class Solution {
public:
    int mod=1e9+7;
    pair<int,int> dp[101][101];

    pair<int,int> help(int i, int j, vector<string>& nums){

        if(i==nums.size() || j==nums[0].size() || nums[i][j]=='X'){
            return {INT_MIN,0};
        }
        if(i==nums.size()-1 && j==nums[0].size()-1){
            return {0,1};
        }

        int x=0;
        pair<int,int> p={-1,-1};
        if(dp[i][j]!=p){
            return dp[i][j];
        }

        if(nums[i][j]=='E'){
            x=0;
        }
        else{
            x=nums[i][j]-'0';
        }
        auto p1=help(i+1,j,nums);
        auto p2=help(i,j+1,nums);
        auto p3=help(i+1,j+1,nums);

        int mx=x+max(p1.first,max(p2.first,p3.first));
        int count=0;

        if(mx==x+p1.first){
            count+=p1.second;
        }
        if(mx==x+p2.first){
            count+=p2.second;
        }
        if(mx==x+p3.first){
            count+=p3.second;
        }
        return dp[i][j]={mx,count%mod};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        pair<int,int> p1={-1,-1};
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                dp[i][j]=p1;
            }
        }
        auto ans=help(0,0,board);
        if(ans.first<0){
            return {0,0};
        }
        return {ans.first, ans.second};
    }
};