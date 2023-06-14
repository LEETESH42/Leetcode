class Solution {
public:
    int find(int x, int parents[]){
        while(parents[x]!=x){
            x=parents[parents[x]];
        }
        return x;
    }

    void makeUnion(int x, int y, int parent[], int rank[]){
        int parX=find(x,parent);
        int parY=find(y,parent);

        if(parX==parY){
            return;
        }
        else if(rank[parX]<rank[parY]){
            parent[parX]=parY;
        }
        else if(rank[parX]>rank[parY]){
            parent[parY]=parX;
        }
        else{
            parent[parY]=parX;
            rank[parX]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1){
            return -1;
        }
        int parent[n];
        int rank[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto con:connections){
            makeUnion(con[0], con[1], parent, rank);
        }
        set<int> group;
        for(int i=0;i<n;i++){
            int par=find(i,parent);
            group.insert(par);
        }
        int unions=group.size();
        return unions-1;

    }
};