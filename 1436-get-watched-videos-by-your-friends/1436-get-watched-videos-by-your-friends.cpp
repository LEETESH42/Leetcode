class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> ans;
        vector<int> vis(friends.size(),0);
        vis[id]=1;
        queue<pair<int,int>> q;
        q.push({id,0});

        while(!q.empty()){
            int val=q.front().first;
            int l=q.front().second;
            q.pop();
            if(l==level){
                ans.push_back(val);
            }
            for(auto x:friends[val]){
                if(vis[x]==0){
                    vis[x]=1;
                    q.push({x,l+1});
                }
            }
        }

        map<string,int> mp;
        for(auto x:ans){
            for(auto y:watchedVideos[x]){
                mp[y]++;
            }
        }

        vector<pair<int,string>> res;

        for(auto x:mp){
            res.push_back({x.second,x.first});
        }
        sort(res.begin(),res.end());

        vector<string> fn;
        for(auto x:res){
            fn.push_back(x.second);
        }
        return fn;
    }
};