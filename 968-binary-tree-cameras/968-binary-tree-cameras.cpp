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
    int cam = 0;
    int dfs(TreeNode* node)
    {
        /*
            0 ==> leaf or act as a leaf since its children are covered but do not have camera
            1 ==> node has camera 
            2 ==> if null or it is covered by its child who has a camera and can effectively be considered as null since it wont interfere with its parent
            
            1) if null return 2
            2) if either child is a leaf then increment cam and return 1
            3) if either child has a camera return 2
            4) else return 0
        */
        
        if(node == NULL)
            return 2;
        int l = dfs(node->left) , r = dfs(node->right);
        if(l == 0 || r == 0)
        {
            cam++;
            return 1;
        }
        if(l == 1 ||  r == 1)
            return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root)
    {
        return (dfs(root) == 0 ? 1 : 0) + cam;
    }
};