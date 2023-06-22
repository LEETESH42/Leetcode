class Solution {
public:
    int vis[54][54];
    void fill(){
        for(int i=0;i<54;i++){
            for(int j=0;j<54;j++){
                vis[i][j]=0;
            }
        }
    }

    int bfs(int si, int sj, int ei, int ej, vector<vector<int>>& f){
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{si,sj}});
        int ans=-1;

        int n=f.size();
        int m=f[0].size();

        while(!q.empty()){
            int level=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;

            q.pop();
            if(vis[i][j]){
                continue;
            }
            vis[i][j]=1;

            if(i==ei && j==ej){
                return level;
            }

            if(i+1<n && j<m && vis[i+1][j]==0 && f[i+1][j]){
                q.push({level+1,{i+1,j}});
            }

            if(i<n && j+1<m && vis[i][j+1]==0 && f[i][j+1]){
                q.push({level+1,{i,j+1}});
            }

            if(i-1>=0 && i-1<n && j<m && vis[i-1][j]==0 && f[i-1][j]){
                q.push({level+1,{i-1,j}});
            }

            if(j-1>=0 && i<n && j-1<m && vis[i][j-1]==0 && f[i][j-1]){
                q.push({level+1,{i,j-1}});
            }
        }
        return ans;
    }

    int cutOffTree(vector<vector<int>>& f) {
        int n=f.size();
        int m=f[0].size();

        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f[i][j]>1){
                    v.push_back({f[i][j],{i,j}});
                }
            }
        }

        v.push_back({0,{0,0}});
        int l=v.size();
        
        sort(v.begin(),v.end());
        int ans=0;

        for(int i=0;i<l-1;i++){
            fill();

            int si,sj,ei,ej;
            si=v[i].second.first;
            sj=v[i].second.second;

            ei=v[i+1].second.first;
            ej=v[i+1].second.second;

            int res=bfs(si,sj,ei,ej,f);
            if(res==-1){
                return res;
            }
            ans+=res;
        }
        return ans;
    }
};