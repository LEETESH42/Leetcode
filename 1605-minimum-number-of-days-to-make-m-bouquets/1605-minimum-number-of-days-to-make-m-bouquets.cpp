class Solution {
public:
    bool isValid(vector<int>& b, int m, int k, int time){
        int req=0;
        int count=0;

        for(int i=0;i<b.size();i++){
            if(b[i]<=time){
                count++;
            }
            else{
                req+=(count/k);
                count=0;
            }
        }
        req+=(count/k);
        return req>=m;
    }

    int minDays(vector<int>& b, int m, int k) {
        int n=b.size();
        if((long)m*(long)k>n){
            return -1;
        }
        int low=1;
        int high=*max_element(b.begin(),b.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(b,m,k,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};