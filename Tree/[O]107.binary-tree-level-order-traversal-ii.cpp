/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.72%)
 * Total Accepted:    211.4K
 * Total Submissions: 461.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
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

/*16 ms 13.7 MB cpp*/
class Solution
{
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        return BFS(root);
        //   if(!root)return {};
        //  vector<vector<int>>an;
    }

  private:
    vector<vector<int>> BFS(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> an;
        vector<TreeNode *> cur, next;
        cur.push_back(root);
        while (!cur.empty())
        {
            an.push_back({});
            for (TreeNode *i : cur)
            {
                an.back().push_back(i->val);
                if (i->left)
                    next.push_back(i->left);
                if (i->right)
                    next.push_back(i->right);
            }
            cur.swap(next);
            next.clear();
        }
        reverse(an.begin(), an.end());
        return an;
    }
    void DFS(TreeNode *root, int depth, vector<vector<int>> &an)
    {
        if (!root)
            return;

        while (an.size() <= depth)
            an.push_back({});
        an[depth].push_back(root->val);
        DFS(root->left, depth + 1, an);
        DFS(root->right, depth + 1, an);
    }
};
