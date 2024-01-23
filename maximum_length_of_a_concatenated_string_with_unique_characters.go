func solve(arr []string, index int, mp []int) int {
    if index == len(arr) {
        return 0
    }

    var take int
    notTake := solve(arr, index+1, mp)
    flag := false

    for _, ch := range arr[index] {
        if mp[ch-'a'] == 1 {
            flag = true
        }
        mp[ch-'a']++
    }

    if flag {
        take = -1e9
    } else {
        take = len(arr[index]) + solve(arr, index+1, mp)
    }

    for _, ch := range arr[index] {
        mp[ch-'a']--
    }
    return max(take, notTake)
}

func maxLength(arr []string) int {
    mp := make([]int, 26)
    return solve(arr, 0, mp)
}

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
