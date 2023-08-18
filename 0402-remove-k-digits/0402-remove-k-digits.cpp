class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);

        int n=num.size();

        for(int i=1;i<n;i++){
            while(st.empty()==false && st.top()>num[i] && k>0){
                k--;
                st.pop();
            }
            if(st.empty() && num[i]=='0'){
                continue;
            }
            st.push(num[i]);
        }

        while(st.empty()==false && k>0){
            st.pop();
            k--;
        }

        if(st.empty()){
            return "0";
        }

        while(!st.empty()){
            num[n-1]=st.top();
            st.pop();
            n-=1;
        }
        return num.substr(n);
    }
};