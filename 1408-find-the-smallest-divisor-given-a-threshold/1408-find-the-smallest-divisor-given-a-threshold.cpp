class Solution {
public:
    bool isValid(vector<int>& nums, int t, int v){
        int value=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%v==0){
                value+=nums[i]/v;
            }
            else{
                value+=nums[i]/v;
                value++;
            }
        }
        return value<=t;
    }

    int smallestDivisor(vector<int>& nums, int t) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isValid(nums,t,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};