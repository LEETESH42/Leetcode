class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> mp(1e5+1,0);
        
        for(int i=0;i<nums1.size();i++){
            mp[abs(nums1[i]-nums2[i])]++;
        }

        int k=k1+k2;

        for(int i=1e5;i>0;i--){
            int count=mp[i];
            if(count==0){
                continue;
            }
            if(count>=k){
                mp[i]-=k;
                mp[i-1]+=k;
                break;
            }
            else{
                mp[i-1]+=count;
                mp[i]=0;
                k-=count;
            }
        }
        long long sum=0;

        for(int i=1;i<1e5+1;i++){
            sum+=1LL*mp[i]*i*i;
        }
        return sum;
    }
};