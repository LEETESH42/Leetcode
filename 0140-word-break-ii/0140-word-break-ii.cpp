class Solution {
public:
    void solve(int ind, string s, string curr, unordered_set<string> set, vector<string>& res){
        if(ind==s.length()){
            curr.pop_back();
            res.push_back(curr);
        }

        string str="";
        for(int i=ind;i<s.length();i++){
            str.push_back(s[i]);
            if(set.count(str)){
                solve(i+1,s,curr+str+" ",set,res);
            }
        }

    }

    vector<string> wordBreak(string s, vector<string>& w) {
        unordered_set<string> set;
        vector<string> res;

        for(auto it:w){
            set.insert(it);
        }
        string curr="";
        solve(0,s,curr,set,res);
        return res;
    }
};