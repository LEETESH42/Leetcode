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
    void dfs(TreeNode* root, int val, int depth, int d){
        if(!root){
            return;
        }

        if(depth==d){
            TreeNode* n1=new TreeNode(val);
            TreeNode* n2=new TreeNode(val);

            n1->left=root->left;
            n2->right=root->right;

            root->left=n1;
            root->right=n2;
            return ;    
        }
        dfs(root->left,val,depth,d+1);
        dfs(root->right,val,depth,d+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node= new TreeNode(val);
            node->left=root;
            return node;
        }
        dfs(root,val,depth,2);
        return root;
    }
};