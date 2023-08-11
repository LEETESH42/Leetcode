class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n,vector<int>(n,1));
        vector<vector<int>> left(n,vector<int>(n,0));
        vector<vector<int>> right(n,vector<int>(n,0));
        vector<vector<int>> up(n,vector<int>(n,0));
        vector<vector<int>> down(n,vector<int>(n,0));

        for(int i=0;i<mines.size();i++){
            mat[mines[i][0]][mines[i][1]]=0;
        }

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++;
                    left[i][j]=count;
                }
                else{
                    count=0;
                    left[i][j]=count;
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==1){
                    count++;
                    right[i][j]=count;
                }
                else{
                    count=0;
                    right[i][j]=count;
                }
            }
        }

        for(int j=0;j<n;j++){
            int count=0;
            for(int i=0;i<n;i++){
                if(mat[i][j]==1){
                    count++;
                    up[i][j]=count;
                }
                else{
                    count=0;
                    up[i][j]=count;
                }
            }
        }

        for(int j=0;j<n;j++){
            int count=0;
            for(int i=n-1;i>=0;i--){
                if(mat[i][j]==1){
                    count++;
                    down[i][j]=count;
                }
                else{
                    count=0;
                    down[i][j]=count;
                }
            }
        }

        bool flag=false;
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    flag=true;
                    int mn=min(min(left[i][j],right[i][j]), min(up[i][j],down[i][j]));
                    ans=max(ans,mn);
                }
            }
        }

        if(flag){
            return ans;
        }
        return 0;

    }
};