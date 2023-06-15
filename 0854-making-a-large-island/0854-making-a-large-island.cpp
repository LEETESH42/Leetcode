class DisjointSet{
	
public:
    vector<int> parent,size;
	DisjointSet(int n){
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=0;i<n+1;i++){
			parent[i]=i;
			size[i]=1;
		}
	}

	int findUpar(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=findUpar(parent[node]);
	}

	void unionBySize(int u, int v){
		int ulp_u=findUpar(u);
		int ulp_v=findUpar(v);

		if(ulp_u==ulp_v){
			return;
		}
		if(size[ulp_u]<size[ulp_v]){
			parent[ulp_u]=ulp_v;
			size[ulp_v]+=size[ulp_u];
		}
		else{
			parent[ulp_v]=ulp_u;
			size[ulp_u]+=size[ulp_v];
		}
	}
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        int n=grid.size();
        DisjointSet ds(n*n);

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    continue;
                }
                for(int i=0;i<4;i++){
                    int newRow=row+dr[i];
                    int newCol=col+dc[i];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]==1){
                        int nodeNo=row*n+col;
                        int adjNo=newRow*n+newCol;

                        ds.unionBySize(nodeNo,adjNo);
                    }
                }
            }
        }

        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    continue;
                }
                set<int> cmp;

                for(int ind=0;ind<4;ind++){
                    int newRow=i+dr[ind];
                    int newCol=j+dc[ind];

                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n){
                        if(grid[newRow][newCol]==1){
                            cmp.insert(ds.findUpar(newRow*n+newCol));
                        }
                    }
                }

                int sizeTotal=0;
                for(auto it:cmp){
                    sizeTotal+=ds.size[it];
                }
                mx=max(mx,sizeTotal+1);
            }
        }

        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUpar(i)]);
        }

        return mx;
    }
};