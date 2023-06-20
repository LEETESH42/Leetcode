class Solution {
public:
    void dfs(int st, int sc, int iniColour, int color, int delRow[], int delCol[], vector<vector<int>>& ans, vector<vector<int>>& image){
        ans[st][sc]=color;
        int n=image.size();
        int m=image[0].size();

        for(int i=0;i<4;i++){
            int nRow=st+delRow[i];
            int nCol=sc+delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==iniColour && ans[nRow][nCol]!=color){
                dfs(nRow,nCol,iniColour,color,delRow,delCol,ans,image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColour=image[sr][sc];
        vector<vector<int>> ans=image;

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        
        dfs(sr,sc,iniColour,color,delRow,delCol,ans,image);
        return ans;
    }
};