class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n=a.size();
        for(int i=0;i<n;i++){
            int flag=1;

            while(!st.empty() && (st.top()>0 && a[i]<0)){
                if(abs(st.top())<abs(a[i])){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(a[i])){
                    st.pop();
                }
                flag=0;
                break;
            }
            if(flag){
                st.push(a[i]);
            }
        }

        vector<int> ans(st.size());

        for(int i=ans.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};