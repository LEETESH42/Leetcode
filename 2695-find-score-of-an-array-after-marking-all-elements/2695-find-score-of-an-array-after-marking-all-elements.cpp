class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> marked(n+1,0);

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(!pq.empty()){
            int val=pq.top().first;
            int index=pq.top().second;
            pq.pop();

            if(!marked[index]){
                marked[index]=1;
                ans+=val;

                if(index<n-1){
                    marked[index+1]=1;
                }
                if(index>0){
                    marked[index-1]=1;
                }
            }
        }
        return ans;
    }
};