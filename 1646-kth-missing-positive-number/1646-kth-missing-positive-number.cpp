class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        if(arr[0]-1>=k){
            return k;
        }
        if(arr[n-1]-n<k){
            return arr[n-1]+(k-(arr[n-1]-n));
        }
        
        int low=0,high=n-1;
        int res=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]-mid-1<k){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return arr[res]+(k-(arr[res]-res-1));

    }
};