func minFallingPathSum(matrix [][]int) int {
    rows := len(matrix)
	cols := len(matrix[0])

	for i := 1; i < rows; i++ {
		for j := 0; j < cols; j++ {
			curr := matrix[i-1][j]
			if j != 0 {
				curr = int(math.Min(float64(curr), float64(matrix[i-1][j-1])))
			}
			if j != cols-1 {
				curr = int(math.Min(float64(curr), float64(matrix[i-1][j+1])))
			}
			matrix[i][j] += curr
		}
	}

	ans := math.MaxInt

	for i := 0; i < cols; i++ {
		ans = int(math.Min(float64(ans), float64(matrix[rows-1][i])))
	}

	return ans
}

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
