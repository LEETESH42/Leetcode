class Solution {
public:
    void solve(int open, int close, string s, vector<string>& ans){
        if(open==0 && close==0 ){
            ans.push_back(s);
            return;
        }
        if(open!=0){
            string s1=s;
            s1+='(';
            solve(open-1,close,s1,ans);
            
        }
        if(close>open){
            string s2=s;
            s2+=')';
            solve(open,close-1,s2,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> ans;
        solve(n,n,s,ans);
        return ans;
    }
};