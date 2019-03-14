/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (46.95%)
 * Total Accepted:    310.8K
 * Total Submissions: 662K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */

/*
Runtime: 92 ms
Memory Usage: 21.8 MB
*/
class Solution {
public:
    void search(vector<int>& candidates, int pos, int target, vector<int> temp,
        vector<vector<int>>& an)
    {
        if (target == 0) {
            an.push_back(temp);
            return;
        }
        if (pos >= candidates.size())
            return;
        int c = target / candidates[pos];
        for (int i = 0; i <= c; i++) {
            for (int j = 0; j < i; j++) {
                temp.push_back(candidates[pos]);
            }
            search(candidates, pos + 1, target - i * candidates[pos], temp, an);
            for (int j = 0; j < i; j++) {
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> an;
        search(candidates, 0, target, temp, an);
        return an;
    }
};
