class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if((n - i) >= citations[i]){
                ans = citations[i];
            }
            else{
                ans = max(ans, n - i);
                break;
            }
        }
        return ans;
    }
};