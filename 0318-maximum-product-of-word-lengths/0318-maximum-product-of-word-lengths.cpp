class Solution {
public:
    int maxProduct(vector<string>& words) {
        // basically we have to do multiplication of two indexes word length, where the two indexes 
        // word do not have a word in common.
        
        unordered_map<int,int> mp;
        int ans=0,n=words.size();

        for(int i=0;i<n;i++){
            int mask=0;

            for(int j=0;j<words[i].size();j++){
                int pos=int(words[i][j]-'a')+1;
                mask|=(1<<pos);
            }
            mp[i]=mask;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mp[i]&mp[j])==0){
                    int pro=words[i].size()*words[j].size();
                    ans=max(ans,pro);
                }
            }
        }
        return ans;
    }
};