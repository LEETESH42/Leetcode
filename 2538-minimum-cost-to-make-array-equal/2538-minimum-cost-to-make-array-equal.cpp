class Solution {
public:
    long long calculateSum(vector<int>& nums, vector<int>&cost, long long median){
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(1ll*nums[i]-median)*(1ll*cost[i]); 
        }
        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long total=0,sum=0;
        long long n=cost.size();

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i], cost[i]});
        }

        sort(v.begin(), v.end());

        for(int i=0;i<n;i++){
            sum+=1ll*v[i].second;
        }

        long long median;
        int i=0;

        while(total<(sum+1)/2 && i<n){
            total+=1ll*v[i].second;
            median=v[i].first;
            i++;
        }
        return calculateSum(nums, cost, median);
    }
};