import java.util.Vector;
import java.util.List;
import java.util.ArrayList;



class Tetris {
    private List<List<Character>> board;
    //private List<List<Character>> shapesVector;
    private int width;
    private int height;

    /**
     * 
     */
    public Tetris() {
    }


    public Tetris(int input_height,int input_width) {//initializes the board with vector
    
        height = input_height;
        width = input_width;
        List<List<Character>> temp = new ArrayList<>();
        for (int i = 0; i < height; i++) {
            temp.add(new ArrayList<>());
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    temp.get(i).add('0');
                } else {
                    temp.get(i).add(' ');
                }
            }
        }
        board = temp;
    }


    //getBoard
    public List<List<Character>> getBoard() {
        return board;
    }
    

    public void drawBoard() {

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    System.out.print(board.get(i).get(j));
                }
                System.out.println();
            }
    
    }


    public void drawBoard(int countRow) {
        // draw board logic with countRow parameter
    }


    public void checkUserInput() {
        // check user input logic


    }



    public void add(List<List<Character>> tetromino) {
        //adds vector to middle of the board
        for (int i = 0; i < tetromino.size(); i++) {
            for (int j = 0; j < tetromino.get(i).size(); j++) {
                board.get(i + 1).set((width / 2) + j - 2, tetromino.get(i).get(j));
            }
        }
    }
    
    
    
    

    public void animatePieces(List<List<Character>> tetrominoVec, char choice) {
        // animate pieces logic
     
            System.out.print("\033[0J"); // erase from cursor until end of screen
            System.out.print("\033[s"); // save the cursor position
            
            
            add(tetrominoVec); // add tetromino vector to the one time in middle of the board
            
            for (int i = 1; i <= height - 4; i++) {
                //draws,scrols and sleep one time then go back to saved position
                drawBoard();
                scrollTetros(tetrominoVec, i, choice);
            
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            
                System.out.print("\033[u"); // go to saved cursor position
            }
            System.out.print("\033[M"); // cursor moves one line up
    
    }


    public void scrollTetros(List<List<Character>> tetromino_vec, int row_count, char choice) {
       
        for (int i = 0; i < tetromino_vec.size(); i++) {
            for (int j = 0; j < tetromino_vec.get(i).size(); j++) {
                if (board.get(row_count+3).get((width/2)+j-1) != ' ' || board.get(row_count+3).get((width/2)+j-2) != ' ') {
                    break;
                } else {
                    if (choice == 'L' || choice == 'l') {
                        board.get(i+3+row_count).set((width/2)+j-2, tetromino_vec.get(i).get(j));
                        board.get(i+3+row_count).set((width/2)+j-1, tetromino_vec.get(i).get(j));
                        board.get(i+row_count).set((width/2)+j-2, ' ');
                        board.get(i+row_count+2).set((width/2)+j-1, ' ');
                    } else if (choice == 'J' || choice == 'j') {
                        board.get(i+3+row_count).set((width/2)+j-2, tetromino_vec.get(i).get(j));
                        board.get(i+3+row_count).set((width/2)+j-3, tetromino_vec.get(i).get(j));
                        board.get(i+row_count).set((width/2)+j-2, ' ');
                        board.get(i+row_count+2).set((width/2)+j-3, ' ');
                    } else if (choice == 'I' || choice == 'i') {
                        board.get(i+3+row_count).set((width/2)+j-2, tetromino_vec.get(i).get(j));
                        board.get(i+2+row_count).set((width/2)+j-2, ' ');
                        board.get(i+1+row_count).set((width/2)+j-2, ' ');
                    } else {
                        board.get(i+2+row_count).set((width/2)+j-2, tetromino_vec.get(i).get(j));
                        board.get(i+row_count).set((width/2)+j-2, ' ');
                    }
                }
            }   
        }
    }
    
}
