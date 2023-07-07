/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int> mp;

    TreeNode* build(vector<int>& pre, int preSt, int preE, vector<int>& in, int inSt, int inE){
        if(preSt>preE || inSt>inE){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[preSt]);
        int idx=mp[pre[preSt]];
        int len=idx-inSt;

        root->left=build(pre,preSt+1,preSt+len,in, inSt, idx-1);
        root->right=build(pre,preSt+len+1,preE,in,idx+1,inE);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        TreeNode* root=build(pre,0,pre.size()-1,in,0,in.size()-1);
        return root;
    }
};