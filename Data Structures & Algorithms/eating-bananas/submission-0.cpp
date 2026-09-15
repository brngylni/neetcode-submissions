class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = -1;
        for (size_t i = 0; i < piles.size(); i++) {
            max = std::max(max, piles[i]);
        }

        int left = 1;
        int right = max;
        int temp;
        int prev = right;
        while (left <= right) {
            temp = (right + left) / 2;
            long long hours = 0;
            for (size_t j = 0; j < piles.size(); j++) {
                hours += std::ceil(static_cast<double>(piles[j]) / temp);
            }
            if (hours <= h) {
                prev = std::min(prev, temp);
                right = temp - 1;
            }else{
                left = temp + 1;
            }
        }
        return prev;
    }
};
