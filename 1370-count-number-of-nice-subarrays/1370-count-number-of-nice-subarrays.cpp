class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                v.push_back(i);
            }
        }
        if(v.size()<k){
            return 0;
        }
        int i=0,j=k-1,ans=0;

        while(j<v.size()){
            int left=0;
            if(i==0){
                left=v[i]+1;
            }
            else{
                left=v[i]-v[i-1];
            }
            int right=0;
            if(j==v.size()-1){
                right=n-v[j];
            }
            else{
                right=v[j+1]-v[j];
            }

            ans+=left*right;
            i++;
            j++;
        }
        return ans;
    }
};