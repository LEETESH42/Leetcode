class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }

        queue<pair<int,int>> wait;

        int tick=0;
        while((!pq.empty()) || (!wait.empty())){
            tick++;

            while(!wait.empty() && (wait.front().first==tick)){
                int count=wait.front().second;
                pq.push(count);
                wait.pop();
            }

            if(!pq.empty()){
                int count=pq.top();
                count--;
                pq.pop();
                if(count>0){
                    if(n==0){
                        pq.push(count);
                    }
                    else{
                        wait.push({tick+n+1,count});
                    }
                }

            }

        }
        return tick;
    }
};