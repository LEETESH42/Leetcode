class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nonTake=prev1;
            prev2=prev1;
            prev1=max(take,nonTake);
        }
        return prev1;
    }
};