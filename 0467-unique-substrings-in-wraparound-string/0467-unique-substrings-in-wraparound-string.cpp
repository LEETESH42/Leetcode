class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n=s.size();
        vector<int> alpha(26,0);
        int mxl=1;

        for(int i=0;i<n;i++){
            if(i>0 &&(s[i-1]-'a'+1)%26==(s[i]-'a')){
                mxl++;
            }
            else{
                mxl=1;
            }
            alpha[s[i]-'a']=max(alpha[s[i]-'a'],mxl);
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=alpha[i];
        }
        return ans;
    }
};