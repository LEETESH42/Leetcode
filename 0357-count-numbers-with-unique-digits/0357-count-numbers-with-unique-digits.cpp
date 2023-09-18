class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        int start=9;
        int ans=10;
        int curr=9;

        while(n-->1 && start){
            curr*=(start--);
            ans+=curr;
        }
        return ans;
    }
};