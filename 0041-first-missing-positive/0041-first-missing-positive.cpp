class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;

        while(i<n){
            if(nums[i]<n && nums[i]>0 && nums[i]!=nums[nums[i]-1]){
                swap(nums[nums[i]-1], nums[i]);
            }
            else{
                i++;
            }
        }

        i=0;
        for(i=0;i<n;i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return i+1;

    }
};