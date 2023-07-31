class Solution {
public:
    void solve(int i, string o, string digits, vector<string>& s, vector<string>& ans){
        if(i>=digits.size()){
            ans.push_back(o);
            return;
        }

        int index=digits[i]-'0';
        string str=s[index];
        for(int j=0;j<str.size();j++){
            char c=str[j];
            o.push_back(c);
            solve(i+1,o,digits,s,ans);
            o.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        solve(0,"",digits,s,ans);
        return ans;
    }
};