//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    void solve(int idx,string S, string st, vector<string> &ans){
        if(idx==S.size()){
            ans.push_back(st);
            return;
        }
        string op1=st+" ";
        op1.push_back(S[idx]);
        string op2=st;
        op2.push_back(S[idx]);
        
        solve(idx+1,S,op1,ans);
        solve(idx+1,S,op2,ans);
    }

    vector<string> permutation(string S){
        // Code Here
        vector<string> s;
        string st;
        st.push_back(S[0]);
        solve(1,S,st,s);
        return s;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends