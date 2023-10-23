class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.size();
        int result=0;

        string left="";
        string right="";

        for(int i=0;i<n;i++){
            left+=text[i];
            right=text[n-i-1]+right;
            if(left==right){
                result++;
                left="";
                right="";
            }
        }
        return result;
    }
};