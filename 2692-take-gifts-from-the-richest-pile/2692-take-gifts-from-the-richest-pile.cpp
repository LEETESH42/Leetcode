class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        long long sum=0;

        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }

        int count=k;
        while(count>0){
            int temp=pq.top();
            pq.pop();
            pq.push(sqrt(temp));
            count--;
        }

        while(pq.size()>0){
            int temp=pq.top();
            sum+=temp;
            pq.pop();
        }
        return sum;
    }
};