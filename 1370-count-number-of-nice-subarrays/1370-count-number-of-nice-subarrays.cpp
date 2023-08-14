class Solution {
public:
    int solve(vector<int>& nums, int k){
        int low=0, high=0;
        int ans=0;

        for(high=0;high<nums.size();high++){
            if(nums[high]%2){
                k--;
            }
            while(k<0){
                if(nums[low]%2!=0){
                    k++;
                }
                low++;
            }
            ans+=high-low+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};