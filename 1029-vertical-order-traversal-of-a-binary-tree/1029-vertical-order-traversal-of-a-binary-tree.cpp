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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;

        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push({root,{0,0}});

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            TreeNode* temp=top.first;
            int vertical = top.second.first;
            int level=top.second.second;
            
            mp[vertical][level].insert(temp->val);
            if(temp->left!=NULL){
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right!=NULL){
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        
        for(auto i:mp){
            vector<int> v;
            for(auto j: i.second){
                for(auto g: j.second){
                    v.push_back(g);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};