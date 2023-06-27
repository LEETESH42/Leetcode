class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> a;
        find(0,ans,a,s);
        return ans;
    }

    void find(int ind, vector<vector<string>> &ans, vector<string> &a, string s){
        if(ind==s.size()){
            ans.push_back(a);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                a.push_back(s.substr(ind,i-ind+1));
                find(i+1, ans, a, s);
                a.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }

};