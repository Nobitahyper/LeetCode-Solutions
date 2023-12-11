class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(0, current, 0, candidates, target, result);
        return result;
    }

private:
    void dfs(int index, vector<int>& current, int total, const vector<int>& candidates, int target, vector<vector<int>>& result) {
        if (total == target) {
            result.push_back(current);
            return;
        }
        if (index >= candidates.size() || total > target) {
            return;
        }

        
        current.push_back(candidates[index]);
        dfs(index, current, total + candidates[index], candidates, target, result);

        
        current.pop_back();
        dfs(index + 1, current, total, candidates, target, result);
    }
};





