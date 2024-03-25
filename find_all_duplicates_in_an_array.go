func findDuplicates(nums []int) []int {
    ans := make([]int, 0)

    for _, val := range nums {
        if val < 0 {
            val *= -1
        }

        if nums[val-1] < 0 {
            ans = append(ans, val)
        }
        nums[val-1] *= -1
    }
    return ans
}
