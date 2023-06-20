class Solution {
public:
    int delRow[4]={-1,0,1,0};
    int delCol[4]={0,-1,0,1};

    void dfs(int sr, int sc, int initalColor, int color, vector<vector<int>>& image, vector<vector<int>>& ans){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nRow=sr+delRow[i];
            int nCol=sc+delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==initalColor && ans[nRow][nCol]!=color){
                dfs(nRow,nCol,initalColor,color,image,ans);
            }

        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];
        vector<vector<int>> ans=image;
        
        dfs(sr,sc,initialColor,color,image,ans);
        return ans;

    }
};