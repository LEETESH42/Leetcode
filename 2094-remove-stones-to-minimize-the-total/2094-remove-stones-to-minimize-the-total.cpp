class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(int i=0;i<piles.size();i++){
            q.push(piles[i]);
        }
        while(k--){
            int num = q.top();
            q.pop();
            int p = num/2;
            num = num-p;
            
            q.push(num);
        }
        int ans = 0;
        while(!q.empty()){
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};