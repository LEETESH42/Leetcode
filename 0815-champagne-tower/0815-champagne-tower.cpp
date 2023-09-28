class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        vector<double> curr(1,poured);

        for(int i=0;i<=qr;i++){
            vector<double> next(i+2,0);
            for(int j=0;j<=i;j++){
                if(curr[j]>=1){
                    next[j]+=(curr[j]-1)/2.0;
                    next[j+1]+=(curr[j]-1)/2.0;
                    curr[j]=1;
                }
            }
            if(i!=qr){
                curr=next;
            }
        }
        return curr[qg];
    }
};