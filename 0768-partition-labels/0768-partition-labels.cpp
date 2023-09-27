class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.size();
        vector<int> res;

        unordered_map<char,int> mp;

        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int curr=0;
        int end=0;

        for(int i=0;i<n;i++){
            char ch=s[i];
            end=max(end,mp[ch]);
            curr++;

            if(i>=end){
                res.push_back(curr);
                curr=0;
            }
        }
        return res;
    }
};