class Solution {
   public:
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
		int n = A.size();
		vector<int> freq(n + 1), ans(n);
		int curr = 0;

		for (int i = 0; i < A.size(); i++) {
			freq[A[i]]++;
			freq[B[i]]++;

			if (freq[B[i]] == 2) {
				freq[B[i]]++;
				curr++;
			}

			if (freq[A[i]] == 2) {
				freq[A[i]]++;
				curr++;
			}

			ans[i] = curr;
		}

		return ans;
	}
};

// Time Complexity: O(n)
// Space Complexity: O(n)