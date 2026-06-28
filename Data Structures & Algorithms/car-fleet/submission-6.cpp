class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // Sort arrays in parallel
        vector<pair<int, int>> pairs;
        for(int i=0; i<position.size(); i++){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end(), greater<>());

        // Unzip
        for(int i=0; i<pairs.size(); i++){
            position[i] = pairs[i].first;
            speed[i] = pairs[i].second;
        }

        // Free vector by swapping with an empty one
        vector<pair<int, int>>().swap(pairs);
        stack<double> times;
        
        for(int i = 0; i < position.size(); i++){
            double time = (target - position[i]) / static_cast<double>(speed[i]);
            if(times.empty()){
                times.push(time);
                continue;
            }
            if(times.top() < time){
                times.push(time);
            }
        }
        return times.size();
    }
};
