class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0,ans=0;
        vector<int> a(26,0);
        int maxoccur=0;
        for(int i=0;i<s.size();i++){
            a[s[i]-'A']++;
            if(maxoccur<a[s[i]-'A']){
                maxoccur=a[s[i]-'A'];   
            }
            while(i-j-maxoccur+1 > k){
                a[s[j]-'A']--;
                j++;
                for(int st=0;st<26;st++){
                    if(maxoccur<a[st]){
                        maxoccur=a[st];
                    }
                }
            }
            ans=max(ans,i-j+1);
            
        }
        return ans;
    }
};