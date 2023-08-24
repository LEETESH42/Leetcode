class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq(score.begin(), score.end());
        int count=0;

        unordered_map<int,string> mp;

        if(!pq.empty()){
            mp[pq.top()]="Gold Medal";
            pq.pop();
            count++;
        }

        if(!pq.empty()){
            mp[pq.top()]="Silver Medal";
            pq.pop();
            count++;
        }

        if(!pq.empty()){
            mp[pq.top()]="Bronze Medal";
            pq.pop();
            count++;
        }

        while(!pq.empty()){
            count++;
            mp[pq.top()]=to_string(count);
            pq.pop();
        }

        vector<string> res;

        for(int i=0;i<score.size();i++){
            res.push_back(mp[score[i]]);
        }
        return res;
    }
};