class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-2;i++){
            int st=i+1,end=n-1;
            while(st<end){
                int sum=nums[i]+nums[st]+nums[end];
                if(abs(sum-target)<abs(closest-target)){
                    closest=sum;
                }
                if(sum==target){
                    return target;
                }
                else if(sum<target){
                    st++;
                }
                else{
                    end--;
                }
            }
        }
        return closest;
    }
};