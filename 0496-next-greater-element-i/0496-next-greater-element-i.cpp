class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        int n=nums2.size();
        for(int j=n-1;j>=0;j--){
            if(st.size()==0){
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top()>nums2[j]){
                ans.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<nums2[j]){
                while(st.size()>0 && st.top()<nums2[j]){
                    st.pop();
                }
                if(st.size()==0){
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(st.top());
                }
            }
            st.push(nums2[j]);
        }
        reverse(ans.begin(),ans.end());
        // return ans;

        map<int,int> mp;

        for(int i=0;i<ans.size();i++){
            mp[nums2[i]]=ans[i];
        }

        vector<int> final;
        for(int i=0;i<nums1.size();i++){
            final.push_back(mp[nums1[i]]);
        }
        return final;
    }
};