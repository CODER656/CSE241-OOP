#include <iostream>
#include "util.h"

using namespace std;
using namespace FurkanT;

int main(int argc, char const *argv[])
{
    int board_height,board_width,direction,move_count,rot_dir,rot_count;
    char choice;  


    cout << "Please enter tetris board's height:";
    cin >> board_height;
    cout << "Please enter tetris board's width:";
    cin >> board_width;

    while( board_height<10  || board_width<10 ){
        cout << "Both must be higher than 10\n";
        cin >> board_height >> board_width;
    }
 
    Tetris tetris(board_height,board_width);

    cout << "Please select a tetromino type (I, O, T, J, L, S, Z), press R for random tetromino or Q for quit"<<endl;

    //cout<<"\x1b[s";  //save the cursor position
    cout <<"\n\n\n\n";


    while(choice != 'q' || choice != 'Q'){
        cin >> choice;
        Tetromino tetromino(tetromino.convert_shapes(choice)); //converting char input to shapes enum and send to the constructer
        
        
        cout << "Which direction you want to rotate? (L=1,R=2): ";
        cin >> rot_dir;
        cout << "How many times you want to rotate?: ";
        cin >> rot_count;

       cout << "Which direction you want to move? (L=1,R=2): ";
        cin >> direction;
        cout << "How many times you want to move?: ";
        cin >> move_count;
        cout <<"\n\n\n\n\n\n\n";
        
        tetris.animate_pieces(tetromino.get_shapePtr(),choice,tetromino,tetris,direction,move_count);

        tetromino.rotate(tetromino,rot_dir,rot_count);
     }
     

     //cout<<"\x1b[u";// save alınan pozisyona git


    return 0;
}
