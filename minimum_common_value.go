func getCommon(nums1 []int, nums2 []int) int {
    i, j := 0, 0

    for i < len(nums1) && j < len(nums2) {
        if nums1[i] == nums2[j] {
            return nums1[i]
        } else if nums1[i] > nums2[j] {
            j++
        } else {
            i++;
        }
    } 
    return -1
}

// Time Complexity : O(n)
// Space Complexity : O(1)