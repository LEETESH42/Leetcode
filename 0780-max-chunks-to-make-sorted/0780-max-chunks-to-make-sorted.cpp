class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> m(n);

        int mx=0;

        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
            m[i]=mx;
        }

        int count=0;

        for(int i=0;i<n;i++){
            if(m[i]==i){
                count++;
            }
        }
        return count;
    }
};