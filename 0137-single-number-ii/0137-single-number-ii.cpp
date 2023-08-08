class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // count the bits of a number, and take %3 of the set bits
        // for negative numbers we are taking a 32 index

        vector<int> bits(33,0);
        int n=nums.size();

        for(int i=0;i<n;i++){
            int t=nums[i];
            if(t<0){
                bits[32]++;
                t=abs(t);
            }
            int j=0;
            while(t){
                bits[j]+=t&1;
                t=t/2;
                j++;
            }
        }

        long long res=0;
        for(int i=0;i<=31;i++){
            res+=(bits[i]%3)*pow(2,i);
        }
        if(bits[32]%3!=0){
            return res*(-1);
        }
        return res;
    }
};