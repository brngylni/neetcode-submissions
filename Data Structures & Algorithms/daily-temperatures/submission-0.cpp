class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int, int>> st;
        vector<int> result(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            int t = temperatures[i];

            while(!st.empty() && t > st.top().first){
                auto top = st.top();
                result[top.second] = i - top.second;
                st.pop();
            }
            st.push({t, i});
        }
        return result;
    }
};
