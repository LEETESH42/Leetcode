class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[i][j]=1;
        int n=board.size();
        int m=board[0].size();

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int x=0;x<4;x++){
            int nRow=i+delRow[x];
            int nCol=j+delCol[x];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && board[nRow][nCol]=='O'){
                dfs(nRow,nCol,vis,board);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }

        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};