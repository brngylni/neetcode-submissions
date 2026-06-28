class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1, max=-1;
        int temp;

        while(i<j){
            temp = (j-i) * min(heights[i], heights[j]);
            if(temp > max)
                max = temp;
            if(heights[i]>heights[j])
                j--;
            else
                i++;
        }
        return max;

    }
};
