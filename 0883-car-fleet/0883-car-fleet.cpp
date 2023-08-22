class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;

        vector<double> diff;

        for(int i=0;i<position.size();i++){
            vec.push_back({position[i],speed[i]});
        }

        sort(vec.begin(),vec.end());

        for(auto x: vec){
            double number=double(target-x.first)/(double)x.second;
            diff.push_back(number);
        }

        stack<double> st;

        for(auto x: diff){
            while(!st.empty() && st.top()<=x){
                st.pop();
            }
            st.push(x);
        }
        return st.size();
    }
};