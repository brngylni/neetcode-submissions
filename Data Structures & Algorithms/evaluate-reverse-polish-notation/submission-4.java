class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<tokens.length; i++){
            try{
                int num = Integer.parseInt(tokens[i]);
                st.push(num);
            }catch(Exception e){
                if(st.size() >= 2){
                    int b= st.pop();
                    int a = st.pop();
                    st.push(evaluate(a, b, tokens[i]));
                }
            }
        }
        
        return st.pop();
    }
    public int evaluate(int num1, int num2, String operator){
        if(operator.equals("+")){
            return num1 + num2;
        }else if(operator.equals("-")){
            return num1 - num2;
        }else if(operator.equals("*")){
            return num1 * num2;
        }else if(operator.equals("/")){
            return ((int)num1 / num2);
        }
        return -1;
    }
}
