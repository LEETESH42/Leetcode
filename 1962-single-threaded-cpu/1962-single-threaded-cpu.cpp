class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();

        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({tasks[0][1],tasks[0][2]});

        int i=1;
        long long int time=tasks[0][0];

        vector<int> ans;

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            ans.push_back(temp.second);
            time+=temp.first;

            while(i<n && time>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(i<n && pq.empty()){
                time=tasks[i][0];
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
        }
        return ans;
    }
};