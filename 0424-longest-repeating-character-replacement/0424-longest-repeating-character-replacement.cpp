class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0;
        int left=0;

        int count=0;
        int res=0;

        map<char,int> mp;

        for(right=0;right<s.size();right++){
            mp[s[right]]++;
            count=max(count,mp[s[right]]);

            if(right-left+1-count>k){
                mp[s[left]]--;
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};