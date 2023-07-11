class Solution {
public:
    bool isValid(int mid, vector<int> piles, int h){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]/mid);
            piles[i]%=mid;
            if(piles[i]>0){
                hours++;
            }
            if(hours>h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1,end=0,ans=0;
        int n=piles.size();

        for(int i=0;i<n;i++){
            end=max(end,piles[i]);
        }
        
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isValid(mid,piles,h)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};