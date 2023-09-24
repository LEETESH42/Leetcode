class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int currsum=0;
        int mx=0;

        unordered_map<int,int> mp;
        mp[0]=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                currsum--;
            }
            else{
                currsum++;
            }

            if(mp.find(currsum)!=mp.end()){
                mx=max(mx,i-mp[currsum]);
            }
            else{
                mp[currsum]=i;
            }
        }
        return mx;
    }
};