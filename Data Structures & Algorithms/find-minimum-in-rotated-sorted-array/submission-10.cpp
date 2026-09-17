class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (right + left) / 2;

        while (left < right) {
            if (nums[left] > nums[right]) {
                if (nums[left] > nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            else if(nums[right] > nums[left]){
                right = mid;
            }

            mid = (right + left) / 2;
            if (left == mid || right == mid) {
                std::cout << "Left = " << left << "\n"
                          << "Right = " << right << "\n"
                          << "Mid = " << mid << "\n";
                return std::min(nums[left], nums[right]);
            }
        }
        return nums[mid];
    }
};
