class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        int rowLen = matrix[0].size() - 1;
        int row;
        while (left <= right) {
            row = (right + left) / 2;

            if (matrix[row][0] > target) {
                right = row - 1;
                continue;
            } else if (matrix[row][rowLen] < target) {
                left = row + 1;
                continue;
            }
            break;
        }

        if (left > right) {
            return false;
        }

        int rowLeft = 0;
        int rowRight = rowLen;
        while (rowLeft <= rowRight) {
            int tempIndex = (rowRight + rowLeft) / 2;
            
            int tempVal = matrix[row][tempIndex];

            if (tempVal > target) {
                rowRight = tempIndex - 1;
                continue;
            } else if (tempVal < target) {
                rowLeft = tempIndex + 1;
                continue;
            }
            return true;
        }
        return false;
    }
};
