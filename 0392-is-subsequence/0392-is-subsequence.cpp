class Solution {
public:
    
    bool solve(int i, string s, int j, string t){
        
        if(i<0 && j>=0){
            return true;
        }
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }

        if(s[i]==t[j]){
            return (solve(i-1,s,j-1,t));
        }
        else{
            return solve(i,s,j-1,t);
        }
    }

    bool isSubsequence(string s, string t) {
        return solve(s.size()-1,s,t.size()-1,t);
    }
};