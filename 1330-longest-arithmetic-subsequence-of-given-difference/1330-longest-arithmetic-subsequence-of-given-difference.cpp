class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        map<int,int> mp;
        
        int mxLen=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]=mp[arr[i]-difference]+1;
            mxLen=max(mxLen,mp[arr[i]]);
        }
        return mxLen;
    }
};