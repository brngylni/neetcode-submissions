class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        for(int i=0; i<nums.length; i++){
            if( i>0 && nums[i] == nums[i-1])
                continue;

            for(int j=i+1, k=nums.length-1; j<k;){
                int sum = nums[i]+ nums[j] + nums[k];
                if(sum == 0){
                    result.add(new ArrayList<Integer>(List.of(nums[i], nums[j], nums[k])));
                    while(nums[j] == nums[++j] && j < k);
                }else if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }
            }
        }
        return result;
    }
}
