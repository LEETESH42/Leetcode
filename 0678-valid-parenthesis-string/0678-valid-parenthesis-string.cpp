class Solution {
public:
    bool checkValidString(string s) {
        stack<int> temp;
        stack<int> a;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                temp.push(i);
            }
            else if(s[i]=='*'){
                a.push(i);
            }
            else{
                if(!temp.empty()){
                    temp.pop();
                }
                else if(!a.empty()){
                    a.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!temp.empty()){
            if(a.empty() || temp.top()>a.top()){
                return false;
            }
            temp.pop();
            a.pop();
        }
        return true;
    }
};