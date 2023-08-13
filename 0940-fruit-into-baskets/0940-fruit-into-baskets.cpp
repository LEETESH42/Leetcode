class Solution {
public:
    int totalFruit(vector<int>& f) {
        map<int,int> mp;
        int i=0,j=0;
        int ans=0;

        int n=f.size();
        while(j<n){
            mp[f[j]]++;
            if(mp.size()<=2){
                ans=max(ans,(j-i+1));
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[f[i]]--;
                    if(mp[f[i]]==0){
                        mp.erase(f[i]);
                    }
                    i++;
                }
                j++;
            }

        }
        return ans;
    }
};