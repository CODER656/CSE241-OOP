#include <iostream>
#include "util.h"
#include <vector>

int main(int argc, char const *argv[])
{  
    int board_height,board_width;
    char choice;


        //getting board height and width from user
        cout << "Please enter tetris board's height:";
        cin >> board_height;
        cout << "Please enter tetris board's width:";
        cin >> board_width;

        while( board_height<10  || board_width<10 ){
            cout << "Please enter a multiples of two for both height and width. Also both must be higher than 10\n";
            cin >> board_height >> board_width;
        }

        Tetris tetris(board_height,board_width);

        cout << "Please select a tetromino type (I, O, T, J, L, S, Z), press R for random tetromino or Q for quit"<<endl;
        cout<<"\x1b[s";  //save the cursor position
        cout <<"\n\n\n\n";


     while(choice != 'q' || choice != 'Q'){
        
        cin >> choice;
        Tetromino tetromino(tetromino.set_shapes(choice)); //converting char input to shapes enum and send to the constructer
        tetromino.rotate(tetromino.get_shape_vector());
        tetris.animate_pieces(tetromino.get_shape_vector(),choice);
     }
     

     cout<<"\x1b[u";// save alınan pozisyona git
   
    return 0;
}
