class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target=times[targetFriend][0];

        sort(times.begin(),times.end());
        int n=times.size();

        priority_queue<int,vector<int>, greater<int>> chair;

        for(int i=0;i<n;i++){
            chair.push(i);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > leaving;

        for(auto v: times){
            int arrival=v[0], dep=v[1];

            while(!leaving.empty() && leaving.top().first<=arrival){
                auto it=leaving.top();
                leaving.pop();
                chair.push(it.second);
            }
            int ch=chair.top();
            chair.pop();
            leaving.push({dep,ch});
            if(arrival==target){
                return ch;
            }
        }
        return -1;
    }
};