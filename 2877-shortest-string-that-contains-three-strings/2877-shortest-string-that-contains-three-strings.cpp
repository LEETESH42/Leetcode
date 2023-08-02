class Solution {
public:
    void isValid(string merged, string &ans){
        if(ans.empty() || merged.size()<ans.size() || (merged.size()==ans.size() && merged<ans)){
            ans=merged;
        }
    }

    string check(string a, string b){
        if(a.find(b)!=string::npos){
            return a;
        }

        int i=min(a.size(),b.size());

        for(;i>=0;i--){
            if(a.substr(a.size()-i)==b.substr(0,i)){
                return a+b.substr(i);
            }
        }
        return a+b;
    }

    string minimumString(string a, string b, string c) {
        vector<string> arr={a,b,c};
        int n=arr.size();
        string ans="";

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i){
                        string merg=check(arr[i],arr[j]);
                        merg=check(merg,arr[k]);
                        isValid(merg,ans);
                    }
                }
            }
        }
        return ans;
    }
};