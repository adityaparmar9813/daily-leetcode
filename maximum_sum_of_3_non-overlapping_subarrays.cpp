class Solution {
   public:
	int dp[100000][4];

	int F(int idx, vector<int>& K_Size_windowSum, int k, int left) {
		if (idx >= K_Size_windowSum.size()) {
			return (left == 0) ? 0 : INT_MIN;
		}

		if (left < 0) {
			return INT_MIN;
		}

		if (dp[idx][left] != -1) {
			return dp[idx][left];
		}

		int take_ith_index =
		    K_Size_windowSum[idx] + F(idx + k, K_Size_windowSum, k, left - 1);
		int not_take_ith_index = F(idx + 1, K_Size_windowSum, k, left);

		return dp[idx][left] = max(take_ith_index, not_take_ith_index);
	}

	void recover(vector<int>& K_Size_windowSum, int k, int idx, int t,
	             vector<int>& res) {
		if (idx >= K_Size_windowSum.size() || t == 0) {
			return;
		}

		int take_ith_index =
		    K_Size_windowSum[idx] + F(idx + k, K_Size_windowSum, k, t - 1);
		int not_take_ith_index = F(idx + 1, K_Size_windowSum, k, t);

		if (take_ith_index >= not_take_ith_index) {
			res.push_back(idx);
			recover(K_Size_windowSum, k, idx + k, t - 1, res);
		} else {
			recover(K_Size_windowSum, k, idx + 1, t, res);
		}
	}

	vector<int> maxSumOfThreeSubarrays(vector<int>& A, int k) {
		memset(dp, -1, sizeof(dp));
		int n = A.size();
		vector<int> P(n, 0);

		P[0] = A[0];

		for (int i = 1; i < A.size(); i++) {
			P[i] = P[i - 1] + A[i];
		}

		vector<int> K_Size_windowSum(n - k + 1);

		for (int i = 0; i <= n - k; i++) {
			if (i == 0) {
				K_Size_windowSum[0] = P[k - 1];
			} else {
				K_Size_windowSum[i] = P[i + k - 1] - P[i - 1];
			}
		}

		vector<int> result;
		F(0, K_Size_windowSum, k, 3);
		recover(K_Size_windowSum, k, 0, 3, result);
		return result;
	}
};
