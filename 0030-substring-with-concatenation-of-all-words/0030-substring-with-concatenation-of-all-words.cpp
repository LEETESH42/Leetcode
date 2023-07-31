class Solution {
public:
    bool same(unordered_map<string,int>& m1, unordered_map<string,int>& m2, int i){
        if(m1.size()!=m2.size()){
            return false;
        }

        for(auto it:m1){
            if(m2[it.first]!=it.second){
                return false;
            }
            m2.erase(it.first);
        }
        return m2.empty();
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int i,j;
        int n=s.length();
        int sz=words.size();

        vector<int> ans;
        unordered_map<string,int> mp;

        for(int i=0;i<sz;i++){
            mp[words[i]]++;
        }

        int wordSize=words[0].size();
        int len=sz*wordSize;

        i=0;
        j=len-1;

        while(j<n){
            bool falg=true;

            unordered_map<string,int> m2;
            for(int ind=i;ind<=j;ind+=wordSize){
                string temp=s.substr(ind,wordSize);
                m2[temp]++;
            }
            if(same(mp,m2,i)==true){
                ans.push_back(i);
            }
            i+=1;
            j+=1;
        }
        return ans;
    }
};