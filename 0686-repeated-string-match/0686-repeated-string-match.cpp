class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str=a;
        while(str.size()<b.size()){
            str+=a;
        }
        if(str.find(b)!=-1){
            return str.size()/a.size();
        }
        str+=a;
        if(str.find(b)!=-1){
            return str.size()/a.size();
        }
        else{
            return -1;
        }
    }
};