class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& q) {
        int n=q.size();
        vector<int> ans(n,-1);

        vector<pair<int,int>> qsort(n);

        for(int i=0;i<n;i++){
            qsort[i]={q[i],i};
        }

        sort(qsort.begin(),qsort.end());
        sort(in.begin(), in.end());

        int m=in.size(), j=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<n;i++){
            while(j<m && in[j][0]<=qsort[i].first){
                pq.push({in[j][1]-in[j][0]+1, in[j][1]});
                j++;
            }
            while(!pq.empty() && pq.top().second<qsort[i].first){
                pq.pop();
            }
            if(!pq.empty()){
                ans[qsort[i].second]=pq.top().first;
            }
        }
        return ans;
    }
};