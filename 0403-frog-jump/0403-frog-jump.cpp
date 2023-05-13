class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,set<int>> mp;
        mp[stones[0]+1]={1};

        for(int i=1;i<stones.size();i++){
            int position=stones[i];
            for(auto it : mp[position]){
                mp[position+it-1].insert(it-1);
                mp[position+it].insert(it);
                mp[position+it+1].insert(it+1);
            }
        }
        return mp[stones.back()].size()!=0;
    }
};