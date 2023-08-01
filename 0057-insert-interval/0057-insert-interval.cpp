class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int j=0;
        while(j<nums.size() && nums[j][0]<newInterval[0]){
            ans.push_back(nums[j]);
            j++;
        }
        if(ans.empty()||ans.back()[1]<newInterval[0]){
            ans.push_back(newInterval);
        }
        else{
            ans.back()[1]=max(ans.back()[1],newInterval[1]);
        }

        for(int i=j;i<nums.size();i++){
            if(ans.back()[1]>=nums[i][0]){
                ans.back()[1]=max(ans.back()[1],nums[i][1]);
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};