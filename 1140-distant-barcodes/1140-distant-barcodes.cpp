class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        if(n<2){
            return barcodes;
        }

        map<int,int>m;
        for(auto i:barcodes){
            m[i]++;
        }

        priority_queue<pair<int, int>>pq;
        for(auto i:m){
            pq.push({i.second, i.first});
        }

        vector<int>ans;
        while(pq.size() >= 2){
            pair<int,int>p1=pq.top();
            pq.pop();

            pair<int,int>p2=pq.top();
            pq.pop();

            ans.push_back(p1.second);
            p1.first--;
            if(p1.first>0){
                pq.push(p1);
            }

            ans.push_back(p2.second);
            p2.first--;
            if(p2.first>0){
                pq.push(p2);
            }

        }
        if(pq.size()==1){
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};