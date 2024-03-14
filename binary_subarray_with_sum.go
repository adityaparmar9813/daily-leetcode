func numSubarraysWithSum(nums []int, goal int) int {
	result := 0
	l, r, sum, tail := 0, 0, 0, 0

	for r < len(nums) {
		sum += nums[r]
		if nums[r] == 1 {
			tail = 0
		}

		for l <= r && sum >= goal {
			if sum == goal {
				tail++
			}
			sum -= nums[l]
			l++
		}
		result += tail
		r++
	}
	return result
}

// Time Complexity : O(n)
// Speed Complexity : O(1)