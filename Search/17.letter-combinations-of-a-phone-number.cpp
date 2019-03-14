/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.57%)
 * Total Accepted:    353.8K
 * Total Submissions: 872K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> an{ "" };
        string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        for (int i = 0; i < digits.size(); i++) {
            vector<string> t;
            string str = dict[digits[i] - '2'];
            for (int j = 0; j < str.size(); j++) {
                for (string s : an)
                    t.push_back(s + str[j]);
            }
            an = t;
        }
        return an;
    }
};
