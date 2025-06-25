class Solution {
   public:
	long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
	                             long long k) {
		vector<int> A1, A2, B1, B2;
		separate(nums1, A1, A2);
		separate(nums2, B1, B2);

		long negCount =
		    (long)A1.size() * B2.size() + (long)A2.size() * B1.size();
		int sign = 1;

		if (k > negCount) {
			k -= negCount;
		} else {
			k = negCount - k + 1;
			sign = -1;
			swap(B1, B2);
		}

		long l = 0, r = 1e10;
		while (l < r) {
			long m = (l + r) / 2;
			if (numProductNoGreaterThan(A1, B1, m) +
			        numProductNoGreaterThan(A2, B2, m) >=
			    k)
				r = m;
			else
				l = m + 1;
		}

		return sign * l;
	}

   private:
	void separate(const vector<int>& A, vector<int>& A1, vector<int>& A2) {
		for (int a : A) {
			if (a < 0)
				A1.push_back(-a);
			else
				A2.push_back(a);
		}
		reverse(A1.begin(), A1.end());
	}

	long numProductNoGreaterThan(const vector<int>& A, const vector<int>& B,
	                             long m) {
		long count = 0;
		int j = B.size() - 1;
		for (long a : A) {
			while (j >= 0 && a * B[j] > m) --j;
			count += j + 1;
		}
		return count;
	}
};

// Time complexity: O(n * log(n))
// Space complexity: O(n)