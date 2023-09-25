class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;

        int mxfreq=0;

        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            mxfreq=max(mxfreq,mp[tasks[i]]);
        }

        int time=(n+1)*(mxfreq-1);
        for(auto it: mp){
            if(it.second==mxfreq){
                time++;
            }
        }
        int t=tasks.size();
        return max(t,time);
    }
};