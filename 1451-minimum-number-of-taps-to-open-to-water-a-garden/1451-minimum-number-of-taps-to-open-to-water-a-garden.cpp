class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mn=0;
        int mx=0;
        int count=0;

        while(mx<n){
            for(int i=0;i<n+1;i++){
                if(i-ranges[i]<=mn && i+ranges[i]>mx){
                    mx=i+ranges[i];
                }
            }
            if(mx==mn){
                return -1;
            }
            mn=mx;
            count++;
        }
        return count;
    }
};