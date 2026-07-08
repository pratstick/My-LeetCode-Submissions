
class Solution {
    vector<string> ans;
    string digits;
    const vector<string> alphabets = {"",    "",    "abc",  "def", "ghi",
                                      "jkl", "mno", "pqrs", "tuv", "wxyz"};

private:
    void helper(int index, string s) {
        if (index == digits.size()) {
            ans.push_back(s);
            return;
        }
        int num = digits[index] - '0';
        for (char c : alphabets[num]) {
            helper(index + 1, s + c);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        helper(0, "");
        return ans;
    }
};