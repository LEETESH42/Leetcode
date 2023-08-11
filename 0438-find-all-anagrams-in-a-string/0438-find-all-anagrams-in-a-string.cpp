class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();

        if(n<k){
            return {};
        }

        vector<int> frq(26,0);
        vector<int> window(26,0);

        for(int i=0;i<k;i++){
            frq[p[i]-'a']++;
            window[s[i]-'a']++;
        }

        vector<int> ans;
        if(frq==window){
            ans.push_back(0);
        }

        for(int i=k;i<n;i++){
            window[s[i-k]-'a']--;
            window[s[i]-'a']++;

            if(frq==window){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};