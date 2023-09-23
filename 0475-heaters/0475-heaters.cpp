class Solution {
public:
    bool solve(int range, vector<int>& houses, vector<int>& heaters){
        int i=0,j=0;
        int n=houses.size();
        int m=heaters.size();

        while(j<n && i<m){
            if( abs(heaters[i]-houses[j]) <= range){
                j++;
            }
            else{
                i++;
            }
        }
        if(j==n){
            return true;
        }
        return false;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int low=0;
        int high=1e9+4;

        int ans;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,houses,heaters)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};