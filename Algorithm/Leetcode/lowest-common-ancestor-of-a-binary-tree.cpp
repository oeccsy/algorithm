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
    TreeNode* lca = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) return nullptr;
        if (p == q) return p;

        findCount(root, p, q);
        return lca;
    }

    int findCount(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) return 0;
        if (lca != nullptr) return 2;

        int totalCount = 0;
        if (root == p || root == q) totalCount++;

        totalCount += findCount(root->left, p, q);
        totalCount += findCount(root->right, p, q);

        if (lca == nullptr && totalCount == 2) lca = root;

        return totalCount;
    }
};