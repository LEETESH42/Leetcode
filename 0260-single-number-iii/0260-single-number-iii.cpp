class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int ans1=0;
        int ans2=0;

        for(int i=0;i<n;i++){
            x=x^nums[i];
        }

        int k=1;
        while(true){
            if((k&x)!=0){
                break;
            }
            k=k<<1;
        }

        for(int i=0;i<n;i++){
            if((nums[i]&k)!=0){
                ans1=ans1^nums[i];
            }
            else{
                ans2=ans2^nums[i];
            }
        }
        return {ans1,ans2};
    }
};