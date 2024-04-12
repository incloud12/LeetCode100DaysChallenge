class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int min = candidates[0];
        vector<int> res;
        int j = 0;
        GenCombination(candidates, j, candidates.size(), target, res);
        return result;
    }
    void GenCombination(
        vector<int>& comb, int j,
        int n, int target, vector<int>& res)
    {
        if (target < 0)
            return;

        if (target == 0)
        {
            result.push_back(res);
            return;
        }

        for (int i = j; i < n; i++)
        {
            res.push_back(comb[i]);
            GenCombination(comb, i, n, target - comb[i], res);
            res.pop_back();
        }
    }
};
