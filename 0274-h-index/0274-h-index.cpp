class Solution {
public:
    int hIndex(vector<int>& c) {
        int n=c.size();
        sort(c.begin(),c.end());

        if(c[0]>=n){
            return n;
        }

        if(n==1){
            return !(c[0]==0);
        }

        for(int i=0;i<n;i++){
            int left=n-i;
            if(c[i]>=left){
                return left;
            }
        }
        return 0;
    }
};