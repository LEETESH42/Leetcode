bool comp(const vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int n=points.size();

        int prev=points[0][1], count=1;

        for(int i=1;i<n;i++){
            if(prev<points[i][0]){
                prev=points[i][1];
                count++;
            }
        }
        return count;
    }
};