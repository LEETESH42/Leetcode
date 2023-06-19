class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        for(int i=1;i<nums.size();i++){
            nums[i]=max(nums[i-1],i+nums[i]);
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==i){
                return false;
            }
        }
        return true;
    }
};