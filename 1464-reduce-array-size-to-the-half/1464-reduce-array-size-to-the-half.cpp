class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->second});
        }

        int count=0;
        int var=0;

        while(count<arr.size()/2){
            count+=pq.top().first;
            var++;
            pq.pop();
        }
        return var;
    }
};