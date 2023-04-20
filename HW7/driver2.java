
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;


public class driver2 {
    public static void main(String[] args) {
        
        int board_height, board_width;
        char choice= 'w';

        Scanner in = new Scanner(System.in);

        // getting board height and width from user
        System.out.print("Please enter tetris board's height:");
        board_height = in.nextInt();
        System.out.print("Please enter tetris board's width:");
        board_width = in.nextInt();

        while (board_height < 15 || board_width < 15) {
            System.out.println("Please enter a multiples of two for both height and width. Also both must be higher than 10\n");
            board_height = in.nextInt();
            board_width = in.nextInt();
        }

        Tetris tetris = new Tetris(board_height, board_width);

        System.out.println("Please select a tetromino type (I, O, T, J, L, S, Z), press R for random tetromino or Q for quit\n");
        

        while (choice != 'q' && choice != 'Q') {
            choice = in.next().charAt(0);

            //Tetromino tetromino = new Tetromino(Tetromino.shapes.valueOf(Character.toString(choice)));
            Tetromino tetromino = new Tetromino(Tetromino.setShapes(choice));

            //tetromino.rotate(tetromino.getShapeVector());
            tetris.animatePieces(tetromino.getShapeVector(), choice);
        }


    
        in.close();
    }
}
