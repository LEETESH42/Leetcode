class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> freq;
        map<int,vector<string>> str;

        for(auto it: words){
            freq[it]++;
        }

        for(auto it: freq){
            str[it.second].push_back(it.first);
        }

        vector<string> res;

        for(auto it=str.rbegin(); it!=str.rend(); it++){
            sort(it->second.begin(), it->second.end(), greater<string>());

            for(int j=it->second.size()-1;j>=0 && k>0 ;j--){
                res.push_back(it->second[j]);
                k--;
            }

        }
        return res;
    }
};