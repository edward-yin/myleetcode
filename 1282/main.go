func groupThePeople(groupSizes []int) (ret [][]int) {
	// group := map[int][] int{}
	group := make(map[int][]int)
	for mIndex, sizeG := range groupSizes {
		group[sizeG] = append(group[sizeG], mIndex)
	}

	for size, people := range group {
		for i := 0; i < len(people); i += size {
			ret = append(ret, people[i:i+size])
		}
	}
	return
}