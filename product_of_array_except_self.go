func productExceptSelf(nums []int) []int {
    ans := make([]int, len(nums))

    product := 1
    for i := 0; i < len(nums); i++ {
        ans[i] = product
        product = product * nums[i]
    }

    product = 1
    for i := len(nums)-1; i >= 0; i-- {
        ans[i] = ans[i] * product
        product = product * nums[i]
    }
    return ans
}

// Time Complexity : O(n)
// Space Complexity : O(n)