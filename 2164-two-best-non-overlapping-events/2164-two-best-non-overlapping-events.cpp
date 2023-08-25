class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        priority_queue<pair<int,pair<int,int>>> pq;

        int mxvalue=0;
        int ans=0;

        sort(events.begin(),events.end());

        for(int i=0;i<n;i++){
            //take out all events which have ending time lesser than the current time and take maximum
            while(!pq.empty() &&(-1*pq.top().first)<events[i][0]){
                mxvalue=max(mxvalue,pq.top().second.second);
                pq.pop();
            }
            ans=max(ans,mxvalue+events[i][2]);
            pq.push({-1*events[i][1],{events[i][0],events[i][2]}});
        }
        return ans;
    }
};