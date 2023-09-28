class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;

        for(int i=0;i<words.size();i++){
            string s1=words[i];

            if(s.size()<s1.size()){
                continue;
            }
            int j=0,k=0;

            while(j<s.size() && k<s1.size()){
                int count1=1, count2=1;
                if(s[j]==s1[k]){
                    while(j<s.size()-1 && (s[j]==s[j+1])){
                        count1++;
                        j++;
                    }
                    while(k<s1.size()-1 && (s1[k]==s1[k+1])){
                        count2++;
                        k++;
                    }
                    if(count1<count2 || (count1>count2 && count1<3)){
                        break;
                    }
                }
                else{
                    break;
                }
                j++;
                k++;
            }
            if(j==s.size() && k==s1.size()){
                ans++;
            }
        }
        return ans;
    }
};