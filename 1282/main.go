
import (
	"sort"
)

func groupThePeople(groupSizes []int) (ret [][]int) {
	group := make(map[int][]int)
	for mIndex, sizeG := range groupSizes {
		group[sizeG] = append(group[sizeG], mIndex)
	}

	// for size, people := range group {
	// 	for i := 0; i < len(people); i += size {
	// 		ret = append(ret, people[i:i+size])
	// 	}
	// }

	var keys []int
	for i := range group {
		keys = append(keys, i)
	}
	sort.Ints(keys)

	for _, k := range keys {
		var len = len(group[k]) / k
		// fmt.Printf("key %d, gourp %d num %d\n", k, group[k], len);
		for i := 0; i < len; i += 1 {
			ret = append(ret, group[k][i*k:i*k+k])
		}
	}
	return
}