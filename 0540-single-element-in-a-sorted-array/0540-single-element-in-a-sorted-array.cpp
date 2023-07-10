class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1;
        int mid;

        while(st<=end){
            mid=st+(end-st)/2;

            if(mid==0 || (nums[mid-1]!=nums[mid]) && (nums[mid+1]!=nums[mid])){
                return nums[mid];
            }

            if(mid%2==1){
                if(nums[mid-1]==nums[mid]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                if(nums[mid+1]==nums[mid]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return mid;
    }
};