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
    int minimumvalue(TreeNode* root){
        int mn=root->val;
        while(root->left!=NULL){
            mn=root->left->val;
            root=root->left;
        }
        return mn;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            root->val=minimumvalue(root->right);
            root->right=deleteNode(root->right,root->val);
        }
        return root;
    }
};