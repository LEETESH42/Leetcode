class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> mx(n);
        mx[n-1]=nums[n-1];

        for(int i=nums.size()-2;i>=0;i--){
            mx[i]=max(nums[i],mx[i+1]);
        }

        int ans=0;
        int i=0;
        int j=0;

        while(i<=nums.size()-1 && j<=nums.size()-1){
            if(nums[i]<=mx[j]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};