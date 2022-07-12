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
    bool sym(TreeNode* node1 , TreeNode* node2)
    {
        if(node1 == NULL && node2 == NULL)
            return true;
        if(node1 && node2 && node1->val == node2->val)
        {
            return (sym(node1->left,node2->right))&&(sym(node1->right,node2->left));
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) 
    {
        return sym(root,root);
    }
};