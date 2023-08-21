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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }

        int mx=max_element(nums.begin(),nums.end())-nums.begin();

        TreeNode* root= new TreeNode(nums[mx]);

        vector<int> lefta;
        for(int i=0;i<mx;i++){
            lefta.push_back(nums[i]);
        }

        vector<int> righta;

        for(int i=mx+1;i<nums.size();i++){
            righta.push_back(nums[i]);
        }

        root->left=constructMaximumBinaryTree(lefta);
        root->right=constructMaximumBinaryTree(righta);
        return root;
    }
};