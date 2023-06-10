class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]){
            return -1;
        }
        grid[0][0]=1;
        queue<vector<int>> q;
        q.push({0,0,1});

        while(!q.empty()){
            vector<int> curr=q.front();
            q.pop();

            int x=curr[0];
            int y=curr[1];
            int steps=curr[2];

            if(x==n-1 && y==n-1){
                return steps;
            }

            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    int nx=x+i;
                    int ny=y+j;

                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                        q.push({nx,ny,steps+1});
                        grid[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
    }
};