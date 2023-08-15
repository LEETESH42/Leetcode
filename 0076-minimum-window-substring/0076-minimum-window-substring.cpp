class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        unordered_map<int,int> mp,curr;

        for(auto it: t){
            mp[it]++;
        }

        string ans;
        int i=0,j=0,len=INT_MAX, ansi=-1,ansj=0;
        int req=mp.size();

        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                curr[s[j]]++;
                if(curr[s[j]]==mp[s[j]]){
                    req--;
                }
            }

            while(req==0){
                if(len>j-i+1){
                    len=j-i+1;
                    ansi=i;
                    ansj=j;
                }
                if(mp.find(s[i])!=mp.end()){
                    curr[s[i]]--;
                    if(curr[s[i]]<mp[s[i]]){
                        req++;
                    }
                }
                i++;
            }
            j++;
        }
        if(ansi==-1){
            return "";
        }
        else{
            return s.substr(ansi,ansj-ansi+1);
        }
    }
};