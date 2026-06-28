class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int temp_1, temp_2;
        for(string& str : tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                char ch = str[0];
                temp_1 = numbers.top();
                numbers.pop();
                temp_2 = numbers.top();
                numbers.pop();
                switch(ch){
                    case '+':
                        numbers.push(temp_1 + temp_2);
                        break;
                    case '-':
                        numbers.push(temp_2 - temp_1);
                        break;
                    case '*':
                        numbers.push(temp_1 * temp_2);
                        break;
                    case '/':
                        numbers.push(temp_2 / temp_1);
                        break;
                }
            }else{
                numbers.push(stoi(str));
            }
        }
        return numbers.top();
    }
};
