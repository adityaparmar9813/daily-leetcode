class CustomStack {
	vector<int> st;
	vector<int> inc;
	int size;

  public:
	CustomStack(int maxSize) { size = maxSize; }

	void push(int x) {
		if (st.size() == size) {
			return;
		}
		st.push_back(x);
		inc.push_back(0);
	}

	int pop() {
		if (st.empty()) {
			return -1;
		}
		int top = st.back();
		st.pop_back();

		int add = inc.back();
		inc.pop_back();

		if (!inc.empty()) {
			inc.back() += add;
		}

		return top + add;
	}

	void increment(int k, int val) {
		k = min(k, (int)inc.size());
		if (k > 0) {
			inc[k - 1] += val;
		}
	}
};

// Time Complexity : O(1)
// Space Complexity : O(n)