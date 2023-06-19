class Solution {
public:
    string ans="";
    void expand(int i, int j, string s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        if(ans.size()<j-i){
            ans=s.substr(i+1,j-i-1);
        }
    }

    string longestPalindrome(string s) {
        int mx=1;
        for(int i=0;i<s.size();i++){
            expand(i,i+1,s);
            expand(i,i,s);
        }
        return ans;
    }
};