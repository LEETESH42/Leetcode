class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int k=queries[i][0];
            int trim=queries[i][1];
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>pq;
            for(int j=0;j<nums.size();j++){
                string temp=nums[j];
                string res;
                for(int l=temp.size()-trim;l<temp.size();l++)
                    res+=temp[l];
                pq.push({res,j});
            }
            int top;
            while(!pq.empty() && k-- ){
                top=pq.top().second;
                pq.pop();
            }
            ans.push_back(top);
            
            
        }
        return ans;
        
    }
};