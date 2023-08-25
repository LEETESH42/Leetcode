class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sum=0;
        int n=reward1.size();

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            sum+=reward2[i];
            ans[i]=reward2[i]-reward1[i];
        }

        sort(ans.begin(),ans.end());

        for(int i=0;i<k;i++){
            sum-=ans[i];
        }
        return sum;
    }
};