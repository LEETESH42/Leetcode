class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        reverse(s.begin(),s.end());
        return to_string(x)==s;
    }
};