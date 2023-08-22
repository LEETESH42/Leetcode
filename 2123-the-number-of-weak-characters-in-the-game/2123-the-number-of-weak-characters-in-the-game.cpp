class Solution {
public:
    bool static sorted(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(), pro.end(), sorted);
        int ans=0;
        int mxdef=INT_MIN;

        int n=pro.size();

        for(int i=n-1;i>=0;i--){
            if(pro[i][1]<mxdef){
                ans++;
            }
            else{
                mxdef=pro[i][1];
            }
        }

        return ans;

    }
};