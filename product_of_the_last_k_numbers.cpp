class ProductOfNumbers {
	vector<int> vec;
	vector<int> prefix;
	int lrg = -1;

   public:
	ProductOfNumbers() {}

	void add(int num) {
		vec.push_back(num);

		if (num == 0) {
			lrg = vec.size() - 1;
		}

		if (num != 0 && prefix.size() > 0) {
			int prev = prefix[prefix.size() - 1];

			if (prev != 0) {
				int curr = num * prev;
				prefix.push_back(curr);
			} else {
				prefix.push_back(num);
			}
		} else {
			prefix.push_back(num);
		}
	}

	int getProduct(int k) {
		int end = prefix.size();
		int nom = prefix[end - 1];
		int start = (end - 1) - k;
		int dom = start == -1 || prefix[start] == 0 ? 1 : prefix[start];

		if (lrg > start) {
			return 0;
		}

		return nom / dom;
	}
};

// Time Complexity : O(n)
// Space Complexiy : O(n)