/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (47.13%)
 * Total Accepted:    341.9K
 * Total Submissions: 724.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
/*12 ms 14.8 MB cpp*/
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
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
        return an;
    }
};
/*8 ms 13.8 MB cpp*/
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> an;
        DFS(root, 0, an);
        return an;
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
