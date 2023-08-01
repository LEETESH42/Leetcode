class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        int n=in.size();
        int i=0;

        vector<vector<int>> result;

        while(i<n && in[i][1]<newIn[0]){
            result.push_back(in[i]);
            i++;
        }

        while(i<n && in[i][0]<=newIn[1]){
            newIn[0]=min(newIn[0],in[i][0]);
            newIn[1]=max(newIn[1],in[i][1]);
            i++;
        }
        result.push_back(newIn);
        while(i<n){
            result.push_back(in[i]);
            i++;
        }
        return result;
    }
};