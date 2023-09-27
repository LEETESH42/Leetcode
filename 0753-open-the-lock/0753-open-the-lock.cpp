class Solution {
public:
    int openLock(vector<string>& dead, string target) {
        int res=0;
        unordered_set<string> s(dead.begin(),dead.end());
        queue<pair<string,int>> q;

        if(s.find("0000")!=s.end()){
            return -1;
        }
        q.push({"0000",0});
        s.insert("0000");

        while(q.size()){
            string curr=q.front().first;
            int step=q.front().second;

            if(curr==target){
                return step;
            }
            q.pop();

            for(int i=0;i<4;i++){
                string up=curr, down=curr;
                char u=up[i], d=down[i];

                if(u=='9'){
                    up[i]='0';
                }
                else{
                    up[i]=u+1;
                }
                if(d=='0'){
                    down[i]='9';
                }
                else{
                    down[i]=d-1;
                }

                if(s.find(up)==s.end()){
                    q.push({up,step+1});
                    s.insert(up);
                }
                if(s.find(down)==s.end()){
                    q.push({down,step+1});
                    s.insert(down);
                }
            }
        }
        return -1;
    }
};