func getBit(x int, k int) int {
    return (x >> k) & 1
}

func singleNumber(nums []int) []int {
    xorXY := 0
    for _, num := range nums {
        xorXY ^= num
    }

    pos := 0
    for getBit(xorXY, pos) == 0 {
        pos++
    }

    x := 0
    for _, num := range nums {
        if getBit(num, pos) != 0 {
            x ^= num
        }
    }

    y := xorXY ^ x
    return []int{x, y}
}

// Time Complexity : O(n)
// Space Complexity : O(1)
