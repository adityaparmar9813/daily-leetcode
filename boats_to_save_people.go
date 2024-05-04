func numRescueBoats(people []int, limit int) int {
    sort.Ints(people);

    i, j, ans := 0, len(people)-1, 0

    for i <= j {
        if people[i] + people[j] <= limit {
            i++
        }
        j--
        ans++
    }
    return ans
}

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)
