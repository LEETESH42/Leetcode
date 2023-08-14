class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), mx=0,ans=0,left=0;
        unordered_map<char,int> mp;

        for(int j=0;j<n;j++){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);

            while((j-left+1)-mx>k){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,j-left+1);
        }
        return ans;
    }
};