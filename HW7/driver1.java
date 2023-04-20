import java.util.ArrayList;
import java.util.List;

//test each class method and print the result 

public class driver1 {
    public static void main(String[] args) {


        //Create objects with parameters
        Tetromino tetromino1 = new Tetromino(Tetromino.shapes.I);
        Tetromino tetromino2 = new Tetromino(Tetromino.shapes.O);
        Tetromino tetromino3 = new Tetromino(Tetromino.shapes.T);
      


        //test setShapes method 3 times
        System.out.println(tetromino1.setShapes('I'));
        System.out.println(tetromino2.setShapes('O'));
        System.out.println(tetromino3.setShapes('T'));

        


       //test constructer with 3 different case
        Tetris tetris1 = new Tetris(20,20);
        Tetris tetris2 = new Tetris(10, 10);
        Tetris tetris3 = new Tetris(15, 15);

        //test drawBoard method with 3 different case
        tetris1.drawBoard();
        tetris2.drawBoard();
        tetris3.drawBoard();

        //test add method, it takes list of list,test it 3 times with different cases
        System.out.println("\nADD TESTS\n");
        tetris1.add(tetromino1.getShapeVector());
        tetris1.drawBoard();
        tetris2.add( tetromino2.getShapeVector());
        tetris2.drawBoard();
        tetris3.add( tetromino3.getShapeVector());
        tetris3.drawBoard();

       
        //GetShapeVector test
        System.out.println("\nGET SHAPE VECTOR TESTS\n");
        System.out.println(tetromino1.getShapeVector());
        System.out.println(tetromino2.getShapeVector());
        System.out.println(tetromino3.getShapeVector());



        //test rotate method, it takes list of list, test it 3 times with different cases
        Tetromino tetromino4 = new Tetromino(Tetromino.shapes.z);
        Tetris tetris4 = new Tetris(16, 16);
        tetris4.add(tetromino4.getShapeVector());
        tetromino4.rotate(tetromino4.getShapeVector());
        tetris4.drawBoard();
        

        


        






    }

}