class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        int n=words.size();
        
        for(int i=0;i<n;i++){
            string neww=words[i];
            int len=words[i].size();

            for(int j=1;j<=len;j++){
                string pref=neww.substr(0,j);
                for(int k=0;k<len;k++){
                    string suff=neww.substr(k);
                    mp[pref+'|'+suff]=i+1;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string s=pref+'|'+suff;
        return mp[s]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */