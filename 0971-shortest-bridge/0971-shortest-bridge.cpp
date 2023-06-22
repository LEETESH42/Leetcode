class Solution {
public:

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    bool isValid(int i, int j, int n){
        return (i>=0 && i<n && j>=0 && j<n);
    }

    void dfs(int i, int j, int n, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1){
            return;
        }

        grid[i][j]=-1;

        dfs(i-1,j,n,grid);
        dfs(i+1,j,n,grid);
        dfs(i,j-1,n,grid);
        dfs(i,j+1,n,grid);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        
        bool found=false;
        for(int i=0;i<n;i++){
            if(found){
                break;
            }
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dfs(i,j,n,grid);
                    found=true;
                    break;
                }
            }
        }        

        queue<pair<int,int>> q;
        int steps=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int ni=node.first+dx[i];
                    int nj=node.second+dy[i];

                    if(isValid(ni,nj,n)){
                        if(grid[ni][nj]==1){
                            return steps;
                        }
                        if(grid[ni][nj]==0){
                            grid[ni][nj]=-1;
                            q.push({ni,nj});
                        }
                    }

                }

            }
            steps++;
        }
    return -1;

    }
};