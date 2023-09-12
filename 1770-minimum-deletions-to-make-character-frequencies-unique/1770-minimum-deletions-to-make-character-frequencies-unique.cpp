class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        unordered_set<int> st;

        int ans=0;
        for(auto x: mp){
            while(st.find(x.second)!=st.end() && x.second!=0){
                x.second--;
                ans++;
            }
            st.insert(x.second);
        }
        return ans;
    }
};