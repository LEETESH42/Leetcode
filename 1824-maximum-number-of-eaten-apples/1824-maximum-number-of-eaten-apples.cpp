class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int last=0;
        for(int i=0;i<apples.size();i++){
            last=max(last,i+days[i]);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int count=0;

        for(int i=0;i<last;i++){
            while(pq.size() && pq.top().first<=i){
                pq.pop();
            }
            if(i<apples.size() && apples[i]>0){
                pq.push({days[i]+i, apples[i]});
            }

            if(!pq.empty()){
                auto top=pq.top();
                pq.pop();
                int day=top.first;

                int apple=top.second;
                if(apple>0){
                    count++;
                }
                apple--;
                if(apple>0){
                    pq.push({day,apple});
                }
            }

        }
        return count;
    }
};