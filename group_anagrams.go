func SortString(str string) string {
    s := strings.Split(str, "")
    sort.Strings(s)
    return strings.Join(s, "")
}

func groupAnagrams(strs []string) [][]string {
    mp := make(map[string][]string)
    var ans [][]string

    for _, str := range strs {
        curr := SortString(str)

        mp[curr] = append(mp[curr], str)
    }
    
    for _, val := range mp {
        ans = append(ans, val)
    }
    return ans
}

// Time Complexity : O(n*log(m))
// Space Complexity : O(n)