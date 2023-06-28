class Solution {
public:
    void push(stack<int>& st, vector<int> v){
        for(int i=0;i<v.size();i++){
            st.push(v[i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> st;
        int n=rooms.size();
        push(st,rooms[0]);
        map<int,bool> mp;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            if(!mp[temp]){
                push(st,rooms[temp]);
            }
            mp[temp]=true;
        }
        for(int i=1;i<n;i++){
            if(!mp[i]){
                return false;
            }
        }
        return true;
    }
};