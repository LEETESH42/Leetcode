class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;

            int dist=q.front().second;
            q.pop();
            dis[row][col]=dist;

            for(int i=0;i<4;i++){
                int nRow=row+dr[i];
                int nCol=col+dc[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol]==0){
                    vis[nRow][nCol]=1;
                    q.push({{nRow,nCol},dist+1});
                }

            }
        }
        return dis;
    }
};