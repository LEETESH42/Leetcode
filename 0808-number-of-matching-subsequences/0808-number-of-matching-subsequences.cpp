class Solution {
public:
bool isseq(string s,string&t){
      int i,j;
        i=j=0;
        while(i<s.size() and j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i==s.size()) return true;
        return false;
}
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0;
        unordered_map<string,int>mp;
        for(auto i:words) mp[i]++;
        for(auto i:mp){
            if(isseq(i.first,s)) cnt+=i.second;
        }
        return cnt;
    }
};