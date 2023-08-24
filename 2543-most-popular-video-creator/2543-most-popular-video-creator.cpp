class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long long> mp1;
        unordered_map<string, pair<string,long long>> mp2;
        int n=creators.size();

        for(int i=0;i<n;i++){
            
            string cre=creators[i];
            string id=ids[i];
            int view=views[i];

            if(mp1.find(cre)==mp1.end()){
                mp1[cre]=view;
                mp2[cre]= {id,view};
            }
            else{
                if(view>mp2[cre].second){
                    mp2[cre]={id,view};
                }
                else if(view==mp2[cre].second){
                    string curr=mp2[cre].first>=id? id: mp2[cre].first;
                    mp2[cre]={curr,view};
                }
                mp1[cre]+=view;
            }
        }

        long long mxView=INT_MIN;

        for(auto it=mp1.begin(); it!=mp1.end();it++){
            mxView = max(mxView,it->second);
        }

        vector<vector<string>> ans;

        for(auto it=mp1.begin(); it!=mp1.end(); it++){
            if(it->second == mxView){
                ans.push_back({it->first, mp2[it->first].first});
            }
        }
        return ans;
    }
};