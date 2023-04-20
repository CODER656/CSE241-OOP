import java.util.Vector;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;



class Tetromino {

    public enum shapes {
        I('I'), i('i'), o('o'), O('O'), t('t'), T('T'), j('j'), J('J'), l('l'), L('L'), s('s'), S('S'), z('z'), Z('Z');
        
        private char value;

        private shapes(char value) 
        {
            this.value = value;
        }
    }
    
    private List<List<Character>> shapesVector;
    private int width;
    private int height;

    
    public Tetromino(shapes s) {
        // constructor with enum parameter
            // constructor with enum parameter
            switch (s) {
                case I:
                case i:
                    shapesVector = Arrays.asList(Arrays.asList('I', 'I', 'I', 'I'));
                    width = 4;
                    height = 1;
                    break;
                case O:
                case o:
                    shapesVector = Arrays.asList(Arrays.asList('O', 'O'), Arrays.asList('O', 'O'));
                    width = 2;
                    height = 2;
                    break;
                case T:
                case t:
                    shapesVector = Arrays.asList(Arrays.asList('T', 'T', 'T'), Arrays.asList(' ', 'T', ' '));
                    width = 3;
                    height = 2;
                    break;
                case J:
                case j:
                    shapesVector = Arrays.asList(Arrays.asList(' ', 'J'), Arrays.asList(' ', 'J'), Arrays.asList('J', 'J'));
                    width = 2;
                    height = 3;
                    break;
                case L:
                case l:
                    shapesVector = Arrays.asList(Arrays.asList('L', ' '), Arrays.asList('L', ' '), Arrays.asList('L', 'L'));
                    width = 2;
                    height = 3;
                    break;
                case S:
                case s:
                    shapesVector = Arrays.asList(Arrays.asList(' ', 'S', 'S'), Arrays.asList('S', 'S', ' '));
                    width = 3;
                    height = 2;
                    break;
                case Z:
                case z:
                    shapesVector = Arrays.asList(Arrays.asList('Z', 'Z', ' '), Arrays.asList(' ', 'Z', 'Z'));
                    width = 3;
                    height = 2;
                    break;
                default:
                    System.out.println("Invalid tetromino");
                    break;
            }
        
        
    }
    
    public Tetromino() {
        //default constructor
    }
    
    //assign char user input to shape enum
    /**
     * @param userInput
     * @return
     */
    public static shapes setShapes(char userInput) {
        shapes shape = null;
        switch (userInput) {
            case 'I':
                shape = shapes.I;
                break;
            case 'i':
                shape = shapes.i;
                break;
            case 'O':
                shape = shapes.O;
                break;
            case 'o':
                shape = shapes.o;
                break;
            case 'T':
                shape = shapes.T;
                break;
            case 't':
                shape = shapes.t;
                break;
            case 'J':
                shape = shapes.J;
                break;
            case 'j':
                shape = shapes.j;
                break;
            case 'L':
                shape = shapes.L;
                break;
            case 'l':
                shape = shapes.l;
                break;
            case 'S':
                shape = shapes.S;
                break;
            case 's':
                shape = shapes.s;
                break;
            case 'Z':
                shape = shapes.Z;
                break;
            case 'z':
                shape = shapes.z;
                break;
            default:
                System.out.println("Invalid tetromino");
                break;
        }
        return shape;

    }
    
    public  List<List<Character>> getShapeVector() {
        return shapesVector;
    }
    

    public void rotate(List<List<Character>> willTranspose) {

        transpose(willTranspose);
        reverseVector(willTranspose);
    }

    
    public void transpose(List<List<Character>> vec) {
        // transpose logic
        int rows = vec.size();
        int cols = vec.get(0).size();
        
        List<List<Character>> transposedSkeleton = new ArrayList<>(cols);

        for (int i = 0; i < cols; i++) {
            transposedSkeleton.add(new ArrayList<Character>(rows));
        }

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                transposedSkeleton.get(i).add(vec.get(j).get(i));
            }
        }
        vec.clear();
        vec.addAll(transposedSkeleton);
    }



    
    
    public void reverseVector(List<List<Character>> takeVec) {
        // reverse logic
            for (int i = 0; i < takeVec.size(); i++) {
                int begin = 0;
                int end = takeVec.get(i).size() - 1;
        
                while (begin < end) {
                    swap(takeVec, begin, end);
                    begin++;
                    end--;
                }
            }
                
    }
    
    //method for swapping to list elements
    public void swap( List<List<Character>> vec, int i, int j) {
        List<Character> temp = vec.get(i);
        vec.set(i, vec.get(j));
        vec.set(j, temp);
    

    }



    
    public int getWidth() {
        return width;
    }
    
    public int getHeight() {
        return height;
    }
    
    public void setWidth(int w) {
        width = w;
    }
    
    public void setHeight(int h) {
        height = h;
    }
}
