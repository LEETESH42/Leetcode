class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count_one=0;
        int n=nums.size();

        int count_conse=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count_one++;
            }
        }

        int cnt=0;
        for(int i=0;i<count_one;i++){
            if(nums[i]==1){
                cnt++;
            }
        }

        int consctv=0;

        for(int i=count_one;i<2*n;i++){
            if(nums[(i-count_one)%n]==1){
                cnt--;
            }
            if(nums[i%n]==1){
                cnt++;
            }
            consctv=max(cnt,consctv);
        }
        if(consctv>=count_one){
            return 0;
        }
        else{
            return count_one-consctv;
        }

    }
};