#include <iostream>
#include "util.h"

using namespace FurkanT;


Tetris::Tetris(int input_height, int input_width)
{
    height = input_height;
    width = input_width;

    //vector<vector<char>> temp(height, vector<char>(width));
 
    //write dynamic array for board
    tetris_reserve(board,height,width);

    
    //initializing board
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                board[i][j] = '0';
            else
                board[i][j] = ' ';
        }
    }
}


//constructer, creates arrays of shapes according to user
Tetromino::Tetromino(shapes shape)
{

    switch (shape)
    {
    case shapes::I:
    case shapes::i:
    {
        tet_row = 1;
        tet_col = 4;
        tetro_reserve(shapePtr,1,4);
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                shapePtr[i][j] = 'I';
            }
            
        }
        break;
    }
    case shapes::O:
    case shapes::o:
    {
        tet_row = 2;
        tet_col = 2;
        tetro_reserve(shapePtr,2,2);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                shapePtr[i][j] = 'O';
            }
            
        }

        break;
    }
    case shapes::T:
    case shapes::t:
    {   
        tet_row = 2;
        tet_col = 3;
        tetro_reserve(shapePtr,2,3);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i==0 || (i==1 && j==1))
                   shapePtr[i][j]  = 'T';
                else
                   shapePtr[i][j] = ' ';
            }
            
        }

        break;
    }
    case shapes::J:
    case shapes::j:
    {
        tet_row = 3;
        tet_col = 2;
        tetro_reserve(shapePtr,3,2);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if ((i==0 && j==1) || (i==1 && j==1) || (i==2 && j==0) || (i==2 && j==1))
                   shapePtr[i][j]  = 'J';
                else
                   shapePtr[i][j] = ' ';
            }
            
        }
        break;
    }
    case shapes::L:
    case shapes::l:
    {
        tet_row = 3;
        tet_col = 2;
        tetro_reserve(shapePtr,3,2);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if ((i==0 && j==0) || (i==1 && j==0) || (i==2 && j==0) || (i==2 && j==1))
                   shapePtr[i][j]  = 'L';
                else
                   shapePtr[i][j] = ' ';
            }
            
        }
        break;
    }
    case shapes::S:
    case shapes::s:
    {
        tet_row = 2;
        tet_col = 3;

        tetro_reserve(shapePtr,2,3);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((i==0 && j==1) || (i==0 && j==2) || (i==1 && j==0) || (i==1 && j==1))
                   shapePtr[i][j]  = 'S';
                else
                   shapePtr[i][j] = ' ';
            }
            
        }
        break;
    }
    case shapes::Z:
    case shapes::z:
    {
        tet_row = 2;
        tet_col = 3;
        
        tetro_reserve(shapePtr,2,3);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((i==0 && j==0) || (i==0 && j==1) || (i==1 && j==1) || (i==1 && j==2))
                   shapePtr[i][j]  = 'Z';
                else
                   shapePtr[i][j] = ' ';
            }
            
        }
        break;
    }
    default:
    {
        cout << "Invalid tetromino" << endl;
        break;
    }
    }
}


void Tetris::resize( char **&array,int new_size,int size){

    //create a new array with the new size

    char **new_array = new char*[new_size];
 
    for (int i = 0; i < size; i++) 
        new_array[i] = new char[new_size];

    //copy the old array to the new array
    for(int i = 0; i < size; ++i)
        new_array[i] = array[i];

    //delete the old array
    for(int i = 0; i < size; ++i)
        delete[] array[i];
    delete[] array;


}

void Tetris::tetris_reserve(char **&array,int dim1, int dim2){

     //allocate memory for array
    array = new char*[dim1];
 
    for (int i = 0; i < dim1; i++) {
        array[i] = new char[dim2];
    }

}

void Tetromino::tetro_reserve(char **&array,int dim1, int dim2){

     //allocate memory for array
    array = new char*[dim1];
 
    for (int i = 0; i < dim1; i++) {
        array[i] = new char[dim2];
    }

}


//just prints the board to the screen
void Tetris::draw_board()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

//adds vector to middle of the board
/*void Tetris::add(char **shape){

    for (int i = 0; i < tetromino.size(); i++){
        for (int j = 0; j < tetromino[i].size(); j++){
              board[i+1][(width/2)+j-2] = tetromino[i][j];
         }
    }
}*/


void Tetris::scroll_tetros(char **shape,int row_count,char choice,Tetromino &tet_obj,int dir,int mv_cnt){
 

    int moved=move(tet_obj,dir,mv_cnt);
    
    clear();
    for (int i = 0; i < tet_obj.get_tet_row(); i++)
    {
        for (int j = 0; j < tet_obj.get_tet_col(); j++)
        {    
            clear();
            //checks if the next row is empty or not, if empty stop        
            if (board[row_count+3][(width/2)+j-1] != ' '  || board[row_count+3][(width/2)+j-2] != ' ' ||
                board[row_count+3][moved+j] != ' '  || board[row_count+3][moved+j+1] != ' ' )  
                break;
            else
            {    
                //special conditions for L,I,J tetrominos 
               if (choice=='L' || choice=='l' )
                {
                    board[i+3+row_count][(width/2)+j-2] = shape[i][j];
                    board[i+3+row_count][(width/2)+j-1] = shape[i][j];
                    board[i+row_count][(width/2)+j-2] = ' ';
                    board[i+row_count+2][(width/2)+j-1] = ' ';
                }
                else if(choice=='J' || choice=='j'){
                    board[i+3+row_count][(width/2)+j-2] = shape[i][j];
                    board[i+3+row_count][(width/2)+j-3] = shape[i][j];
                    board[i+row_count][(width/2)+j-2] = ' ';
                    board[i+row_count+2][(width/2)+j-3] = ' ';
                }
                else if(choice =='I' || choice == 'i')
                {
                    board[i+3+row_count][(width/2)+j-2] = shape[i][j];
                    board[i+2+row_count][(width/2)+j-2] = ' ';
                    board[i+1+row_count][(width/2)+j-2] = ' ';
                }
                else if(moved!=0)
                {
                    //scroll moved tetromino
                    board[i+2+row_count][moved+j] = shape[i][j];
                    board[i+row_count][moved+j] = ' ';
                    board[i+row_count][(width/2)+j-2] = ' '; 
                    board[i+row_count+1][(width/2)+j-2] = ' ';
                    board[i+row_count][(width/2)+j-1] = ' '; 
                }
                else{
                    board[i+2+row_count][(width/2)+j-2] = shape[i][j]; //adds tetromino vector to the 2 line down
                    board[i+row_count][(width/2)+j-2] = ' ';  //erase previously written tetromino to give animation effect

                }
            }
        }   
    }

}



 void Tetris::animate_pieces(char **shape,char choice,Tetromino & tetro,Tetris &tetris,int dir,int mv_cnt){
    
    //cout << "\x1b[0J"; //erase from cursor until end of screen
    
    tetris+=tetro;

    

    
    for (int i = 1; i <= height-4; i=i+1){
        
        //draws,scrols and sleep one time then go back to saved position
        cout<<"\x1b[s";  //save the cursor position
        cout << "\x1b[0J"; //erase from cursor until end of screen
        draw_board();
        scroll_tetros(shape,i,choice,tetro,dir,mv_cnt);
        clear();
        usleep(200000);
        cout <<"\x1b[u";// go to saved cursor position
        
    }
    cout <<"\x1bM"; // cursor moves one line up*/
    cout <<"\x1bM"; // cursor moves one line up*/
    cout <<"\x1bM"; // cursor moves one line up*/
    
 }

int Tetris::move(Tetromino & tet_obj,int direcion,int move_count){

    if (direcion == 1)
    {
        for(int mc=0; mc<move_count ; mc++){ //do it move count times
            for (int i = 0; i < tet_obj.get_tet_row(); i++){
                for (int j = 0; j < tet_obj.get_tet_col(); j++)
                {
                    if (board[i+1][(width/2)-j-3] != ' '  && board[i+1][(width/2)-j-4] != ' '  &&
                        board[i+2][(width/2)-j-3] != ' '  && board[i+2][(width/2)-j-4] != ' ')
                        break;
                    else
                    {
                        board[i+1][(width/2)-j-2-mc] = tet_obj.get_shapePtr()[i][j]; //adds tetromino vector to the 2 line down
                        board[i+1][(width/2)-j-mc] = ' ';  //erase previously written tetromino to give animation effect
                    }
                        
                }
            }
         }
       
        return (width/2)-tet_obj.get_tet_col()-move_count; //moved tetromino's leftmost index
    }

    if (direcion == 2)
    {
        for(int mc=0; mc<move_count ; mc++){ //do it move_count times
            for (int i = 0; i < tet_obj.get_tet_row(); i++){
                for (int j = 0; j < tet_obj.get_tet_col(); j++)
                {
                    if (board[i+1][(width/2)-j-1] != ' '  && board[i+1][(width/2)-j] != ' '  &&
                        board[i+2][(width/2)-j-1] != ' '  && board[i+2][(width/2)-j] != ' ')
                        break;
                    else
                    {
                        board[i+1][(width/2)+j-2+mc] = tet_obj.get_shapePtr()[i][j]; //adds tetromino vector to the 2 line down
                        board[i+1][(width/2)+j+mc] = ' ';  //erase previously written tetromino to give animation effect
                    }
                        
                }
            }
         }
       
        return (width/2)+tet_obj.get_tet_col()+move_count-3; //moved tetromino's leftmost index
    }



    return 0;
}
          





 /*if we take the transpose of a matrix and then reverse the rows it will be rotated to right*/
void Tetromino::rotate(Tetromino & obj,int rot_dir,int rot_count) 
{
    for (int i = 0; i < rot_count; i++)
    {
        if (rot_dir==1)
        {
            transpose(obj);
            reverse_array(obj);  
        }
        else if(rot_dir==2)
        {
            for (int i = 0; i < 3; i++)
            {
                transpose(obj);
                reverse_array(obj);
            }
            
        }
    }
   
}



 void Tetromino::transpose(Tetromino & tetro_obj) {

    char **transpose;
    tetro_reserve(transpose,tetro_obj.get_tet_col(),tetro_obj.get_tet_row());

    for (int i=0; i<tetro_obj.get_tet_row(); i++){
        for (int j=0; j<tetro_obj.get_tet_col(); j++){
            transpose[j][i] = shapePtr[i][j];/*swapping rows and columns*/
        }
    }

    shapePtr = transpose;
}


void Tetromino::swap(char* a, char* b) const
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


//reversing the array rows one by one 
void Tetromino::reverse_array(Tetromino & obj)
{
    for (int i = 0; i < obj.get_tet_row(); i++) {
        int begin = 0;
        int end = obj.get_tet_col() - 1;

        while (begin < end){
            swap(&shapePtr[i][begin], &shapePtr[i][end]);
            begin++;
            end--;
        }
    }
}


void Tetris::clear(){

     for (int i = 0; i < height; i++)
     {
        for (int j = 0; j < width; j++)
        {
            if ((i==1 || i==2) && (j!=1 || j!=width-2) && j!= 0 && j != width-1)
            {
                board[i][j]=' ';
            }
        } 
     }
}