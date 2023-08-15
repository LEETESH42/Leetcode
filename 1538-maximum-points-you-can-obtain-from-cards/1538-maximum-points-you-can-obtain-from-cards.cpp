class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int curr=0;
        int ans=0;
        int count=0;
        int n=card.size();
        for(int i=0;i<k;i++){
            curr+=card[i];
            count++;
            ans=max(curr,ans);
        }
        if(k==n){
            return ans;
        }
        count--;
        int j=n-1;
        while(count>=0){
            curr+=card[j];
            curr-=card[count];
            count--;
            j--;
            ans=max(ans,curr);
        }
        return ans;
    }
};