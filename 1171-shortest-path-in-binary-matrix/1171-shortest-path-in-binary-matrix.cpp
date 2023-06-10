class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int level=0;
        int dx[]={0,0,1,1,1,-1,-1,-1};
        int dy[]={1,-1,0,1,-1,0,1,-1};

        queue<pair<int,int>> q;
        q.push({0,0});
        if(grid[0][0]==1){
            return -1;
        }

        while(!q.empty()){
            int l=q.size();
            level++;

            for(int i=0;i<l;i++){
                int x=q.front().first;
                int y=q.front().second;
                
                if(x==n-1 && y==m-1){
                    return level;
                }
                q.pop();

                for(int i=0;i<8;i++){
                    int newRow=x+dx[i];
                    int newCol=y+dy[i];

                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==0){
                        grid[newRow][newCol]=1;
                        q.push({newRow,newCol});
                    }
                }
            }
        }
        return -1;
    }
};