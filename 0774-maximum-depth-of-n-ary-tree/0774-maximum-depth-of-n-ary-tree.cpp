/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> q;
        int length=0;

        if(root==NULL){
            return length;
        }

        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            length++;

            for(int i=0;i<sz;i++){
                Node* curr=q.front();
                q.pop();
                for(Node* &chd: curr->children){
                    q.push(chd);
                }
            }
        }
        return length;
    }
};