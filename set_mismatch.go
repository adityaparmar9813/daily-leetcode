func findErrorNums(nums []int) []int {
        n := len(nums)
        sum := (n*(n+1))/2
        sum_sq := (n*(n+1)*(2*n+1))/6
        curr := 0
        curr_sq := 0

        for i:=0; i < n; i++ {
            curr += nums[i]
            curr_sq += nums[i] * nums[i]
        }

        repeat := ((curr-sum) + (curr_sq-sum_sq) / (curr-sum)) / 2
        absent := repeat - curr + sum
        ans := make([]int, 2)
        ans[0], ans[1] = repeat, absent
        return ans
}

// Time Complexity: O(n)
// Space Complexity: O(1)
