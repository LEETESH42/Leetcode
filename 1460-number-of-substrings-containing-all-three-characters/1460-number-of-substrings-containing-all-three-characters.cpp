class Solution {
public:
    int numberOfSubstrings(string s) {
        int la=-1,lb=-1,lc=-1;
        int ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                la=i;
            }
            else if(s[i]=='b'){
                lb=i;
            }
            else if(s[i]=='c'){
                lc=i;
            }

            if(la !=-1 && lb!=-1 && lc!=-1){
                int last=min(la,min(lb,lc));
                ans+=last+1;
            }
        }
        return ans;
    }
};