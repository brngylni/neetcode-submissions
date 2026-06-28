class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] prefix, suffix;
        prefix = new int[nums.length];
        suffix = new int[nums.length];
        int suffix_product = 1;
        int prefix_product = 1;
        for(int i=0, j=nums.length-1; i<nums.length; i++, j--){
            if(i == 0){
                prefix[i] = 1;
                suffix[j] = 1;
                suffix_product = nums[j];
                prefix_product = nums[i];
                continue;
            }
            prefix[i] = prefix_product;
            suffix[j] = suffix_product;

            suffix_product *= nums[j];
            prefix_product *= nums[i];
        }
        for(int i=0; i<prefix.length; i++){
            prefix[i] *= suffix[i];
        }
        return prefix;
    }
}  
