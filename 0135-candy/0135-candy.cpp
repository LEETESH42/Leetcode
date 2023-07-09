class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        int candy=n, i=1;

        while(i<n){
            if(r[i]==r[i-1]){
                i++;
                continue;
            }

            int peak=0;
            while(r[i]>r[i-1]){
                peak++;
                candy+=peak;
                i++;
                if(i==n){
                    return candy;
                }
            }

            int val=0;
            while(i<n && r[i]<r[i-1]){
                val++;
                candy+=val;
                i++;
            }
            candy-=min(peak,val);
        }
        return candy;
    }
};