/**111. Minimum Depth of Binary Tree
*/
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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int min = 1;
        if (root->left || root->right)
        {
            int a = minDepth(root->left);
            int b = minDepth(root->right);
            int t = (a > b ? b : a);
            min += t == 0 ? (a > b ? a : b) : t;
        }
        return min;
    }
};