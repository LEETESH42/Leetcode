class Solution {
public:

    string solve(int n){
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }


        string curr = solve(n-1);

        string ans = "";

        pair<char,int> ds;

        ds.first = curr[0];
        ds.second = 1;



        for(int i = 1;i<curr.length();i++){
            if(curr[i]!=ds.first){

                ans.push_back('0'+ds.second);
                ans.push_back(ds.first);

                ds.first = curr[i];
                ds.second = 1;

            }
            else{
                ds.first = curr[i];
                ds.second+=1;
            }
        }
        ans.push_back('0'+ds.second);
        ans.push_back(ds.first);

        return ans;

    }

    string countAndSay(int n) {
        return solve(n);
    }
};