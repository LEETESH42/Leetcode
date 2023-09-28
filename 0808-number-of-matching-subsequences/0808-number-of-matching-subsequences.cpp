class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mp;
        int z=0;
        
        for(auto it:s){
            mp[it].push_back(z++);
        }
        int m=words.size();
        int count=0;

        for(int i=0;i<m;i++){
            string s1=words[i];
            int latest=-1;

            for(int j=0;j<s1.size();j++){
                auto it=upper_bound(mp[s1[j]].begin(), mp[s1[j]].end(), latest);
                if(it==mp[s1[j]].end()){
                    break;
                }
                latest=*it;
                if(j==s1.size()-1){
                    count++;
                }
            }
        }
        return count;
    }
};