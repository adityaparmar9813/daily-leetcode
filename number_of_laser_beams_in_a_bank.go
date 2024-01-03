func numberOfBeams(bank []string) int {
	var prev, ans int

	for _, str := range bank {
		count := 0

		byteStr := []byte(str)
		for _, b := range byteStr {
			if b == '1' {
				count++
			}
		}

		if count > 0 {
			ans += (prev * count)
			prev = count
		}
	}
	return ans
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)