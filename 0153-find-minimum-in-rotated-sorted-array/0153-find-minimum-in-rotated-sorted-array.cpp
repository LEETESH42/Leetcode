class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int left=0,right=n-1;
        int ans=INT_MAX;

        while(left<=right){
            int mid=(left+right)/2;
            ans=min(arr[mid],ans);
            ans=min(arr[left],ans);
            ans=min(arr[right],ans);

            if(arr[left]<=arr[mid]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};