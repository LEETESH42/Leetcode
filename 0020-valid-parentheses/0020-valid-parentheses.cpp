class Solution {
public:
    bool isValid(string s) {
        int n=s.size();

        stack<char> st;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                st.push(s[i]);
            }

            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(st.size()==0){
                    return false;
                }
                else if( s[i]==')' && st.top()!='('){
                    return false;
                }
                else if(s[i]==']' && st.top()!='['){
                    return false;
                }
                else if(s[i]=='}' && st.top()!='{'){
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        if(st.size()==0){
            return true;
        }
        else {
            return false;
        }

    }
};