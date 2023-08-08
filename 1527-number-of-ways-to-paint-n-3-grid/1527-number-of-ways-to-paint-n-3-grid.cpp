class Solution {
public:
    int MOD=1e9+7;
    int numOfWays(int n) {
        // there can be 2 pattern RYR or RYG
        // for RYR : RYR , RGR , YRY , YGY , GYG , GRG
        // for RYG : RYG , RGY , GRY, GYR, YRG , YGR
        // we can use RYR if we above we have : YRY , YGY , GRG ,GRY ,YRG i.e 3*RYR + 2*RYG
        // if above is RYG then we can use : YRY , YGY , GRY , YRG i.e 2*RYR + 2*RYG

        int a121=6,a123=6;
        // base condition is we hacve 6 from 121 and 6 from 123
        // Now iterating 

        for(int i=1;i<n;i++){
            int n121=(1l*a121*3 + 1l*a123*2)%MOD;
            int n123=(1l*a121*2 + 1l*a123*2)%MOD;

            a121=n121;
            a123=n123;
        }
        return (a121+a123)%MOD;
    }
};