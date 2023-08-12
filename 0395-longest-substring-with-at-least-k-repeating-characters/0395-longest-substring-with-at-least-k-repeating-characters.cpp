class Solution {
public:
    int solve(string s, int st, int end, int k){
        if(end<k){
            return 0;
        }
        int count[26]={0};
        for(int i=st;i<end;i++){
            count[s[i]-'a']++;
        }
        for(int mid=st;mid<end;mid++){
            if(count[s[mid]-'a']>=k){
                continue;
            }
            int midnext=mid+1;
            while(midnext<end && count[s[midnext]-'a']<k){
                midnext++;
            }
            return max(solve(s,st,mid,k), solve(s,midnext,end,k));
        }
        return (end-st);
    }

    int longestSubstring(string s, int k) {
        int n=s.size();
        return solve(s,0,n,k);
    }
};