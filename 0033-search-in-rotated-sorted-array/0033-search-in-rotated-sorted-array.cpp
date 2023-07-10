class Solution {
public:
    int bs(int st, int end, int t, vector<int>& nums){
        if(st>end){
            return -1;
        }

        int mid= st+(end-st)/2;
        if(nums[mid]==t){
            return mid;
        }

        if(nums[mid]>=nums[st]){
            if(t>=nums[st] && t<=nums[mid]){
                return bs(st,mid-1,t,nums);
            }
            else{
                return bs(mid+1,end,t,nums);
            }
        }
        else{
            if(t>=nums[mid] && t<=nums[end]){
                return bs(mid+1,end,t,nums);
            }
            return bs(st,mid-1,t,nums);
        }
    }

    int search(vector<int>& nums, int target) {
        return bs(0,nums.size()-1,target,nums);
    }
};