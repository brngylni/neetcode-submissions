class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) { 
        
        std::vector<std::pair<int, int>> pairs;
        size_t maxArea = 0;

        for(size_t i=0; i<heights.size(); i++){
            int startIndex = i;
            while(pairs.size() > 0 && pairs[pairs.size() - 1].second > heights[i]){
                std::pair<int, int> top = pairs.back();
                pairs.pop_back();
                maxArea = std::max(maxArea, top.second * (i - top.first));
                startIndex = top.first;
            }
            pairs.push_back(std::make_pair(startIndex, heights[i]));
        }
        for(size_t i=0; i< pairs.size(); i++){
            maxArea = std::max(maxArea, pairs[i].second * (heights.size() - pairs[i].first));
        }

        return maxArea;
    
    }
};
