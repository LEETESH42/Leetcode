class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cntk=0;
        int count=0;
        int ans=-1;
        int l=0,r=0;

        while(r<nums.size()){
            if((nums[r]==0 && cntk<k) || nums[r]==1){
                count++;
                if(nums[r]==0){
                    cntk++;
                }
                r++;
            }
            else{
                ans=max(ans,count);
                if(nums[l]==0){
                    cntk--;
                }
                l++;
                count--;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};