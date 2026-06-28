class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int index = (right + left) / 2; 

        int current = nums[index];

        while(current != target){
            
            if(current < target){
                left = index + 1;
            }else{
                right = index - 1;
            }
            index = (right + left) / 2;
            current = nums[index];
            if(left >= right){
                break;
            }
        }
        if(current == target){
            return index;
        }
        return -1;
        
    }
};
