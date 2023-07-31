class Solution {
public:
    int divide(int div, int di) {
        if(div==INT_MIN && di==-1){
            return INT_MAX;
        }
        if(div==INT_MIN && di==1){
            return INT_MIN;
        }

        long long dvd=abs(div);
        long long dvs=abs(di);

        int ans=0;
        while(dvs<=dvd){
            long long sum=dvs,count=1;
            while(sum<=dvd-sum){
                sum+=sum;
                count+=count;
            }
            ans+=count;
            dvd-=sum;
        }

        if((div<0 && di>0) || (div>0 && di<0)){
            return -ans;
        }
        return ans;
    }
};