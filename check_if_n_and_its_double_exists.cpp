class Solution {
  public:
	bool checkIfExist(vector<int> &arr) {
		sort(arr.begin(), arr.end());

		for (int i = 0; i < arr.size(); i++) {
			int target = 2 * arr[i];
			int left = 0, right = arr.size() - 1;

			while (left <= right) {
				int mid = left + (right - left) / 2;

				if (arr[mid] == target && mid != i) {
					return true;
				} else if (arr[mid] < target) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
		}

		return false;
	}
};

// Time Complexity: O(n * log(n))
// Space Complexity : O(1)