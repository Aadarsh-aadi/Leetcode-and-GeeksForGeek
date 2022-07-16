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
    vector<TreeNode*> generateTreesUseRecursion(const int start, const int end)
{
    if (start > end)
    {
        return { nullptr };
    }

    vector<TreeNode*> trees;
    for (int i = start; i <= end; ++i)
    {
        for (TreeNode* leftRoot : generateTreesUseRecursion(start, i - 1)) // left child, low..i - 1
        {
            for (TreeNode* rightRoot : generateTreesUseRecursion(i + 1, end)) // right child i+1..high
            {
                TreeNode* root = new TreeNode(i);
                root->left = leftRoot;
                root->right = rightRoot;
                trees.push_back(root);
            }
        }
    }

    return trees;
}
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesUseRecursion(1,n);
    }
};