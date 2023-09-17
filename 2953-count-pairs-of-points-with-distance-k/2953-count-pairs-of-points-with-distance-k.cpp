class Solution {
public:
    int countPairs(vector<vector<int>>& co, int k) {
        map<pair<int,int>, int > mp;
        int n=co.size();
        for(int i=0;i<n;i++){
            mp[{co[i][0],co[i][1]}]++;
        }

        long long res=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                int a=co[i][0]^j;
                int b=co[i][1]^(k-j);

                if(mp.find({a,b})!=mp.end()){
                    if(a==co[i][0] && b==co[i][1]){
                        res--;
                    }
                    res+=mp[{a,b}];
                }
            }
        }
        return res/2;
    }
};