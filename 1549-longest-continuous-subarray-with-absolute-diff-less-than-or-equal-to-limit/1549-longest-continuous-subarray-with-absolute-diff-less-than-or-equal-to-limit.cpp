class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int ans=0;
        int i=0,j=0;

        while(i<nums.size()){
            window.insert(nums[i]);

            while(*window.rbegin()-*window.begin()>limit){
                window.erase(window.find(nums[j]));
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};