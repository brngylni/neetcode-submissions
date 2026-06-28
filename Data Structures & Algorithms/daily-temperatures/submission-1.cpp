class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> result(temperatures.size(), 0);
        for(int i = temperatures.size() - 2; i>=0; i--){
            int j = i + 1;

            while(j<temperatures.size() && temperatures[j] <= temperatures[i]){
                if(result[j] == 0){
                    j = temperatures.size();
                    break;
                }
                j += result[j];
            }
            if(j < temperatures.size()){
                result[i] = j-i;
            }
        }
        return result;
    }
};
