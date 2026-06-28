class Solution {
    public int trap(int[] height) {
        int volume=0, prefix_max=0, suffix_max=0;
        int[] suffix, prefix;
        suffix = new int[height.length];
        prefix = new int[height.length];
        
        for(int i=0, j=height.length-1; i<height.length; i++, j--){
            if(height[i] > prefix_max)
                prefix_max = height[i];
            if(height[j] > suffix_max)
                suffix_max = height[j];
            prefix[i] = prefix_max;
            suffix[j] = suffix_max;
        }

        for(int i=0; i<height.length; i++){
            volume += Math.min(prefix[i], suffix[i]) - height[i];
        }
        return volume;
    }
}
