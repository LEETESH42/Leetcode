class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int len=INT_MIN;
        int curr=1;
        bool plusOne=true;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1 && plusOne){
                curr++;
                plusOne=false;
            }
            else if(nums[i+1]-nums[i]==-1 && !plusOne){
                curr++;
                plusOne=true;
            }
            else{
                len=max(len,curr);

                if(nums[i+1]-nums[i]==1){
                    curr=2;
                    plusOne=false;
                }
                else{
                    curr=1;
                    plusOne=true;
                }
            }
        }
        int res=max(len,curr);
        if(res==1){
            return -1;
        }
        return res;
    }
};