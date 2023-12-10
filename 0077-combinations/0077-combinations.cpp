class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(result, path, 1, n, k);
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& path, int start, int n, int k){
        if(k == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            backtrack(result, path, i + 1, n, k - 1);
            path.pop_back();
        }
    }
};