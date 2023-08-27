class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto e: nums){
            if(pq.size()>=k && e>=pq.top()){
                pq.pop();
                pq.push(e);
            }
            else if(pq.size()<k)pq.push(e);
        }
    }
    
    int add(int val) {
        if(pq.size()>=size && val>=pq.top()){
                pq.pop();
                pq.push(val);
            }
            else if(pq.size()<size)pq.push(val);
        return pq.top();
    }
};