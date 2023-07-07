/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> mp;
    vector<int> ans;
 
    void make(TreeNode* root, TreeNode* parent){
        if(root==NULL){
            return;
        }
        mp[root]=parent;
        make(root->left,root);
        make(root->right,root);
    }

    void dfs(TreeNode* root, int k, TreeNode* prev){
        if(root==NULL){
            return;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(root->left!=prev){
            dfs(root->left,k-1,root);
        }
        if(root->right!=prev){
            dfs(root->right,k-1,root);
        }
        if(mp[root]!=prev){
            dfs(mp[root],k-1,root);
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        make(root,NULL);
        dfs(target,k,NULL);
        return ans;
    }
};