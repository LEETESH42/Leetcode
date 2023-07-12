class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        for(int i=0;i<n;i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }

        int mid=0,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            int count=0,temp=0;

            for(int i=0;i<n;i++){
                if(temp+nums[i]<=mid){
                    temp+=nums[i];
                }
                else{
                    count++;
                    temp=nums[i];
                }
            }
            count++;
            if(count<=k){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};