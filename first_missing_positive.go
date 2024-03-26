func firstMissingPositive(nums []int) int {
    for index, val := range nums {
        for val != index+1 && val > 0 && val <= len(nums) && val != nums[val-1] {
            nums[index], nums[val-1] = nums[val-1], nums[index]
            val = nums[index]
        }
    }

    for index, val := range nums {
        if val != index+1 {
            return index+1
        }
    }
    return len(nums) + 1
}


// Time Complexity : O(n)
// Space Complexity : O(1)
