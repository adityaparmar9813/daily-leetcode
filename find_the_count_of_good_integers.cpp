#define ll long long
class Solution {
	ll vectorToNumber(const vector<int>& nums) {
		ll res = 0;
		for (int dig : nums) res = res * 10 + dig;
		return res;
	}

	ll fact(int total, ll f = 1) {
		for (int i = 2; i <= total; i++) f *= i;
		return f;
	}

	ll totalPermutations(map<int, int>& mpp, int total) {
		ll totalDig = fact(total);
		for (auto& palinVal : mpp) totalDig /= fact(palinVal.second);
		return totalDig;
	}

	ll permsWithZero(map<int, int> mpp, int total) {
		return mpp[0] == 0 ? 0 : ([&]() {
			mpp[0]--;
			ll tot = fact(total - 1);
			for (auto& palinVal : mpp) tot /= fact(palinVal.second);
			return tot;
		}());
	}

   public:
	ll res = 0;
	set<map<int, int>> visited;

	void genPal(vector<int>& palin, int left, int right, int divisor,
	            int total) {
		if (left > right) {
			ll palinVal = vectorToNumber(palin);
			if (palinVal % divisor == 0) {
				map<int, int> digMpp;
				for (ll result = palinVal; result; result /= 10)
					digMpp[result % 10]++;
				if (!visited.count(digMpp)) {
					res += totalPermutations(digMpp, total) -
					       permsWithZero(digMpp, total);
					visited.insert(digMpp);
				}
			}
			return;
		}
		for (int dig = (left == 0 ? 1 : 0); dig <= 9; dig++) {
			palin[left] = palin[right] = dig;
			genPal(palin, left + 1, right - 1, divisor, total);
		}
	}

	ll countGoodIntegers(int total, int divisor) {
		vector<int> palin(total);
		genPal(palin, 0, total - 1, divisor, total);
		return res;
	}
};

// Time Complexity : O(10^(n/2) * n)
// Space Complexity : O(n)