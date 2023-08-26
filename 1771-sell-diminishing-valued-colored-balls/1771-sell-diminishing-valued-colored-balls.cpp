class Solution {
public:
    const long M=1e9+7;

    long long getrange(long long first, long long second){
        return ((first+1)*first-(second+1)*second)/2;
    }

    int maxProfit(vector<int>& inv, int orders) {
        sort(inv.begin(), inv.end(),greater<int>());
        int n=inv.size();
        inv.push_back(0);

        long long count=0;
        long long ans=0;

        for(int i=0;i<n;i++){
            int first=inv[i];
            int second=inv[i+1];

            long long wins=getrange(first,second);
            count++;

            if(count*(first-second)<=orders){
                ans=(ans+(count*wins))%M;
                orders-=(count*(first-second));
            }
            else{
                long long div,rem=0;
                div=orders/count, rem=orders%count;
                ans=(ans+(count*getrange(first,first-div)))%M;
                ans=(ans+((first-div)*rem))%M;
                break;
            }
        }
        return ans;
    }
};