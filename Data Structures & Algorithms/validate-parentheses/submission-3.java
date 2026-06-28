class Solution {
    public boolean isValid(String s) {
        Stack<Character> br = new Stack<>();

        for(int i=0; i < s.length(); i++){
            char c = s.charAt(i);

            if(c == '(' || c == '{' || c == '['){
                br.push(c);
                continue;
            }else if(!br.isEmpty()){
                char pop = br.pop();
                if(c == ')' && pop == '(')
                    continue;
                else if(c == '}' && pop == '{')
                    continue;
                else if(c == ']' && pop == '[')
                    continue;
                else
                    return false;
            }
            return false;
        }
        return br.isEmpty();

    }
}
