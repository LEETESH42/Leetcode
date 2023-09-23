class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        vector<int> mn(n);
        mn[0]=nums[0];
        for(int i=1;i<n;i++){
            mn[i]=min(mn[i-1],nums[i]);
        }

        stack<int> st;
        bool found=false;

        for(int j=nums.size()-1;j>=0;j--){
            while(st.size()>0 && st.top()<=mn[j]){
                st.pop();
            }
            if(st.size()>0 && st.top()<nums[j]){
                found=true;
                break;
            }
            st.push(nums[j]);
        }
        return found;
    }
};