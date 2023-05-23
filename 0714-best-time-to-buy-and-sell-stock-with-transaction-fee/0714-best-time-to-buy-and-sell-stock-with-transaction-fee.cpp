class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int aheadNotBuy,aheadBuy,curBuy,curNotBuy;
        aheadNotBuy=0,aheadBuy=0;
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            curNotBuy=max(prices[i]+aheadBuy-fee, aheadNotBuy);
            curBuy=max(-prices[i]+aheadNotBuy, aheadBuy);

            aheadBuy=curBuy;
            aheadNotBuy=curNotBuy;
        }
        return aheadBuy;
    }
};