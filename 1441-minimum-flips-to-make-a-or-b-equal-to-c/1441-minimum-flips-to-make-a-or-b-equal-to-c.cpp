class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a||b||c){
            int x=a&1;
            int y=b&1;
            int z=c&1;

            if((x|y)!=z){
                if(x&y){
                    ans+=2;
                }
                else{
                    ans+=1;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return ans;
    }
};