class Solution {
    public int maxArea(int[] heights) {
        int result = 0;
        for(int i=0, j=heights.length-1; i<j;){
            int volume = Math.min(heights[i], heights[j]) * (j-i);
            if(volume > result){
                result = volume; 
            }
            if(heights[i] > heights[j]){
                j--;
                continue;
            }
            i++;
        }
        return result;
    }
}
