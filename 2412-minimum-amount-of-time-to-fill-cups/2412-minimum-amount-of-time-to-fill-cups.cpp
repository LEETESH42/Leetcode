class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int count = 0;
        for(auto i : amount) {
            pq.push(i);
        }
        while(pq.top() != 0) {
            count++;
            int a = pq.top()-1;
            pq.pop();
            int b = pq.top()-1;
            pq.pop();
            pq.push(a);
            pq.push(b);
        }
        return count;
    }
};