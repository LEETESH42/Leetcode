class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int x) {
        int mx=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            vector<int> temp(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++){
                for(int c=0;c<matrix[0].size();c++){
                    temp[c]+=matrix[j][c];
                }
                
                for(int k=0;k<temp.size();k++){
                    int sum=0;
                    for(int l=k;l<temp.size();l++){
                        sum+=temp[l];
                        if(sum>mx && sum<=x){
                            mx=sum;
                        } 
                    }
                }
            }
        }
        return mx;
    }
};