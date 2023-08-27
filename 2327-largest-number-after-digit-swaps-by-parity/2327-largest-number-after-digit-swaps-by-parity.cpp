class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        string even,odd;
        for(int i=0;i<s.size();i++){
            if(s[i]%2==0)even+=(s[i]);
            else odd+=(s[i]);
        }
        sort(even.begin(),even.end(),greater<int>());
        sort(odd.begin(),odd.end(),greater<int>());
        string ans;
        int pt1=0,pt2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]%2){
                ans+=odd[pt1];
                pt1++;
            }
            else {
                ans+=(even[pt2]);
                pt2++;
            }    
        }
        return stoi(ans);
        
    }
};