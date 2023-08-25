class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int n=orders.size();

        priority_queue<vector<int>> buy;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell;

        for(auto order: orders){
            if(order[2]==0){
                buy.push(order);
            }
            else{
                sell.push(order);
            }

            while(!buy.empty() && !sell.empty() && sell.top()[0]<=buy.top()[0]){
                auto b=buy.top();
                buy.pop();
                auto s=sell.top();
                sell.pop();

                int diff=b[1]-s[1];
                if(diff>0){
                    b[1]=diff;
                    buy.push(b);
                }
                else{
                    s[1]=abs(diff);
                    sell.push(s);
                }
            }
        }

        int ans=0, mod=1e9+7;

        while(!buy.empty()){
            ans=(ans+buy.top()[1])%mod;
            buy.pop();
        }
        while(!sell.empty()){
            ans=(ans+sell.top()[1])%mod;
            sell.pop();
        }
        return ans;
    }
};