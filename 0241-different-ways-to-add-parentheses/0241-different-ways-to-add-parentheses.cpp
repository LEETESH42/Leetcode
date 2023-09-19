class Solution {
public:
    unordered_map<string,vector<int>> dp;
    int ope(int a, int b, char op){
        if(op=='*'){
            return a*b;
        }
        if(op=='-'){
            return a-b;
        }
        if(op=='+'){
            return a+b;
        }
        return 0;
    }
    vector<int> diffWaysToCompute(string ex) {
        if(dp.find(ex)!=dp.end()){
            return dp[ex];
        }

        vector<int> res;
        for(int i=0;i<ex.size();i++){
            if(!isdigit(ex[i])){
                vector<int> left=diffWaysToCompute(ex.substr(0,i));
                vector<int> right=diffWaysToCompute(ex.substr(i+1));

                for(int n1:left){
                    for(int n2:right){
                        res.push_back(ope(n1,n2,ex[i]));
                    }
                }

            }
        }

        if(res.empty()){
            res.push_back(stoi(ex));
        }
        return dp[ex]=res;
    }
};