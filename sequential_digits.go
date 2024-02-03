func sequentialDigits(low int, high int) []int {
	s := "123456789"
	ans := make([]int, 0)

	for i := 0; i < len(s); i++ {
		curr := ""
		for j := i; j < len(s); j++ {
			curr += string(s[j])
			num, _ := strconv.Atoi(curr)
            
			if low <= num && num <= high {
				ans = append(ans, num)
			}
		}
	}

	sort.Ints(ans)
	return ans
}

// Time Complexity: O(1)
// Space Complexity: O(1)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
