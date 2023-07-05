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
    vector<TreeNode*> buildTree(int start, int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }

        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=buildTree(start,i-1);
            vector<TreeNode*> right=buildTree(i+1,end);

            for(TreeNode* l: left){
                for(TreeNode* r: right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }

        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1,n);
    }
};