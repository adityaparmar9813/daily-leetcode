func lengthOfLIS(nums []int) int {
    dp := make([]int, len(nums))
    res := 0

    for i := 0; i < len(nums); i++ {
        dp[i] = 1

        for j := 0; j < i; j++ {
            if nums[j] < nums[i] {
                dp[i] = max(dp[i], dp[j]+1)
            }
        }
        res = max(res, dp[i])
    }
    return res
}

// Time Complexity : O(n^2)
// Space Complexity : O(n)