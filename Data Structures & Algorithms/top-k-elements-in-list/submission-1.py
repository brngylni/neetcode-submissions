class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        results = []
        # Step 2: Group numbers by their frequency
        freq_groups = defaultdict(list)
        for num, count in freq.items():
            freq_groups[count].append(num)

        for i in sorted(freq_groups.keys(), reverse=True):
            if len(results) == k:
                return list(results)
            if len(freq_groups[i]) == 0:
                continue
            for number in freq_groups[i]:
                if not number in results:
                    results.append(number)
        return results