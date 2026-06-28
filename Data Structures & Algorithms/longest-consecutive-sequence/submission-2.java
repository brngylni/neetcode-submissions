class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)
            return 0;
        Set<Integer> set =  Arrays.stream(nums)  // Convert to IntStream
                                          .boxed()          // Convert int to Integer
                                          .collect(Collectors.toCollection(HashSet::new));
        int max=1, count=1, temp=0;
        for(int num : set){
            if(!set.contains(num-1)){
                count = 1;
                temp = num+1;
                while(true){
                    if(set.contains(temp++)){
                        count++;
                        continue;
                    }
                    break;
                }
                if(count > max)
                    max = count;
            }
        }
        return max;
    }
}
