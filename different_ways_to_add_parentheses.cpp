class Solution {
  public:
	vector<int> diffWaysToCompute(string expression) {
		unordered_map<string, vector<int>> memo;
		return helper(expression, memo);
	}

	vector<int> helper(string expr, unordered_map<string, vector<int>> &memo) {
		if (memo.find(expr) != memo.end()) {
			return memo[expr];
		}

		vector<int> result;
		for (int i = 0; i < expr.size(); i++) {
			char c = expr[i];
			if (c == '+' || c == '-' || c == '*') {
				vector<int> left = helper(expr.substr(0, i), memo);
				vector<int> right = helper(expr.substr(i + 1), memo);

				for (int l : left) {
					for (int r : right) {
						if (c == '+') {
							result.push_back(l + r);
						} else if (c == '-') {
							result.push_back(l - r);
						} else {
							result.push_back(l * r);
						}
					}
				}
			}
		}

		if (result.empty()) {
			result.push_back(stoi(expr));
		}

		memo[expr] = result;
		return result;
	}
};

// Time Complexity : O(n ^ 3)
// Space Complexity : O(n ^ 2)