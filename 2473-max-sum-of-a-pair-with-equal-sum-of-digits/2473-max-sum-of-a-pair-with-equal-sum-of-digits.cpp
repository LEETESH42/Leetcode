class Solution {
public:
    int solve(int numb){
        int x=0;
        while(numb>0){
            x+=numb%10;
            numb/=10;
        }
        return x;
    }

    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            int sum=solve(nums[i]);
            mp[sum].push_back(nums[i]);
            cout<<sum<<" ";
        }
        int ans=-1;
        for(auto it:mp){
            sort(it.second.begin(),it.second.end(), greater<int>());
            
            int val=-1;
            if(it.second.size()>=2){
                val+=it.second[0]+it.second[1];
            }
            ans=max(ans,val);
        }
        if(ans!=-1){
            return ans+1;
        }
        return ans;
    }
};