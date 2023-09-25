class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res=0, n=nums.size();

        if(n<3){
            return 0;
        }

        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int pos=lower_bound(nums.begin(),nums.end(),nums[i]+nums[j])-nums.begin();
                if(pos>j){
                    res+=(pos-j-1);
                }
            }
        }
        return res;
    }
};