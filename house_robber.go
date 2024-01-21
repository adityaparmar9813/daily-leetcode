func rob(nums []int) int {
    if len(nums) == 1 {
        return nums[0]
    }

    b, a := nums[len(nums)-1], nums[len(nums)-2]

    for i := len(nums)-3; i >= 0; i-- {
        temp := a
        a = nums[i]+b
        b = max(temp, b)
    }
    return max(a, b)
}

// Time Complexity: O(n)
// Space Complexity: O(1)
