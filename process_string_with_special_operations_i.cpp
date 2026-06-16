class Solution {
   public:
	string processStr(string s) {
		bool front = true;

		deque<char> dq;
		deque<char> temp;

		int n = s.size();

		for (int i = 0; i < n; i++) {
			if (s[i] == '*') {
				if (!dq.empty()) {
					if (front) {
						dq.pop_front();
					} else {
						dq.pop_back();
					}
				}
			} else if (s[i] == '#') {
				temp = dq;

				if (front) {
					while (!temp.empty()) {
						dq.push_front(temp.back());
						temp.pop_back();
					}
				} else {
					while (!temp.empty()) {
						dq.push_back(temp.front());
						temp.pop_front();
					}
				}
			} else if (s[i] == '%') {
				front = !front;
			} else {
				if (front) {
					dq.push_front(s[i]);
				} else {
					dq.push_back(s[i]);
				}
			}
		}

		string ans;

		while (!dq.empty()) {
			ans.push_back(dq.front());
			dq.pop_front();
		}

		if (front) {
			reverse(ans.begin(), ans.end());
		}

		return ans;
	}
};

// Time Complexity: O(n * k)
// Space Complexity: O(n * k)