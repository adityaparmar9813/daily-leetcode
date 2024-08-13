class Solution {
public:
  void solve(int index, vector<vector<int>> &ans, vector<int> &curr,
             vector<int> &candidates, int target) {
    if (target == 0) {
      ans.push_back(curr);
      return;
    }
    if (target < 0) {
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (i > index && candidates[i] == candidates[i - 1]) {
        continue;
      }
      curr.push_back(candidates[i]);
      solve(i + 1, ans, curr, candidates, target - candidates[i]);
      curr.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;

    sort(candidates.begin(), candidates.end());
    solve(0, ans, curr, candidates, target);

    return ans;
  }
};

// Time Complexity : O(2 ^ n)
// Space Complexity : O(n)
