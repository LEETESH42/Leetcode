class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0,i=0;
        int ans=0;
        int n=s.size();
        int mx=0;

        vector<int> freq(26,0);

        for(int j=0;j<n;j++){
            freq[s[j]-'A']++;
            if(mx<freq[s[j]-'A']){
                mx=freq[s[j]-'A'];
            }
            while(j-i+1-mx>k){
                freq[s[i]-'A']--;
                i++;
                for(int x=0;x<26;x++){
                    if(mx<freq[x]){
                        mx=x;
                    }
                }
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};