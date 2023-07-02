class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int last=0;
        long long ans=0;

        multiset<int> st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);

            while(st.size()>1 && *st.rbegin()- *st.begin()>2){
                st.erase(st.find(nums[last]));
                last++;
            }
            ans+=i-last+1;
        }
        return ans;
    }
};