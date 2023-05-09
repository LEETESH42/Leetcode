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
    int solve(TreeNode* start){
        if(start==NULL){
            return 0;
        }

        int left=solve(start->left);
        int right=solve(start->right);

        return 1+max(left,right);
    }

    int maxDepth(TreeNode* root) {
        TreeNode* start=root;
        return solve(start);
    }
};