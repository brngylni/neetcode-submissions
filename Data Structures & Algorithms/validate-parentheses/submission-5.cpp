class Solution {
public:
    bool isValid(string s) {
        map<char, char> brackets = {
            {')', '('}, 
            {'}', '{'},
            {']', '['},
            };
        
        stack<char> control;

        for(char& c : s){
            if(!control.empty() && brackets.count(c)){
                char top = control.top();
                if(top != brackets[c]){
                    return false;
                }
                control.pop();
                continue;
            }
            control.push(c);
        }
    

        return control.empty();
    }
};
