/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) return nullptr;

        TreeNode* rootFind = (root == p || root == q) ? root : nullptr;
        if (rootFind) return root;

        TreeNode* leftFind = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightFind = lowestCommonAncestor(root->right, p, q);
        if (leftFind && rightFind) return root;

        return leftFind ? leftFind : rightFind;
    }
};