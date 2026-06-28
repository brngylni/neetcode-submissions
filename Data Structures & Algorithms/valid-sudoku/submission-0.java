class Solution {
    public boolean isValidSudoku(char[][] board) {

            ArrayList<HashSet<Integer>> rows = new ArrayList<HashSet<Integer>>();
            ArrayList<HashSet<Integer>> columns = new ArrayList<HashSet<Integer>>();
            ArrayList<HashSet<Integer>> squares = new ArrayList<HashSet<Integer>>();

            for (int i = 0; i < board.length; ++i){
                rows.add(new HashSet<Integer>());
                columns.add(new HashSet<Integer>());
                squares.add(new HashSet<Integer>());
            }

            for(int i=0; i < board.length; i++){
                for(int j=0; j < board[i].length; j++){
                    int num = board[i][j];
                    if(Character.isDigit(num)){
                        int square_index =  (i / 3) * 3 + (j / 3);
                        if(rows.get(i).contains(num) || columns.get(j).contains(num) || squares.get(square_index).contains(num)){
                            return false;
                        }
                        rows.get(i).add(num);
                        columns.get(j).add(num);
                        squares.get(square_index).add(num);
                    }
                }
            }
            return true;



    }
}
