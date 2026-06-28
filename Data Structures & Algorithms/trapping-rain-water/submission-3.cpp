class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix, suffix;
        int i=0, j=height.size()-1, pref_max=-1, suf_max=-1;

        while(i<height.size()){
            if(height[i] > pref_max)
             {   prefix.push_back(height[i]);
                pref_max = height[i];
             }
            else{
                prefix.push_back(pref_max);
            }

            if(height[j] > suf_max){
                suffix.push_back(height[j]);
                suf_max = height[j];
            }
            else{
                suffix.push_back(suf_max);      
            }
            i++;
            j--;
            }

        i=1;
        int trapped_water=0;
        int preffix_max, suffix_max;
        while(i<height.size()){
            preffix_max = prefix[i-1];
            suffix_max = suffix[height.size() - i - 2];
            trapped_water += max(min(preffix_max, suffix_max) - height[i], 0);
            i++;
        }
        for (int i = 0; i < prefix.size(); i++)
            cout << prefix[i] << " ";
        
        cout << "\n";
        
        for (int i = 0; i < suffix.size(); i++)
            cout << suffix[i] << " ";

        return trapped_water;
    }
};
