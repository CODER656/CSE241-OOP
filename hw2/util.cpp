#include <iostream>
#include "util.h"
#include <vector>

Tetris::Tetris(int input_height, int input_width)
{
    height = input_height;
    width = input_width;

    vector<vector<char>> temp(height, vector<char>(width));
 
    //initializing board
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                temp[i][j] = '0';

            else
                temp[i][j] = ' ';
        }
    }
    board = temp;
}

//constructer, creates vectors of shapes according to user
Tetromino::Tetromino(shapes shape)
{

    switch (shape)
    {
    case shapes::I:
    case shapes::i:
    {
        shapes_vector = {{'I', 'I', 'I', 'I'}};
        break;
    }
    case shapes::O:
    case shapes::o:
    {
        shapes_vector = {{'O', 'O'},
                         {'O', 'O'}};

        break;
    }
    case shapes::T:
    case shapes::t:
    {
        shapes_vector = {{'T', 'T', 'T'},
                         {' ', 'T',  ' ',}};
        break;
    }
    case shapes::J:
    case shapes::j:
    {
        shapes_vector = {{' ', 'J'},
                         {' ', 'J'},
                         {'J', 'J'}};
        break;
    }
    case shapes::L:
    case shapes::l:
    {
        shapes_vector = {{'L', ' '},
                         {'L', ' '},
                         {'L', 'L'}};
        break;
    }
    case shapes::S:
    case shapes::s:
    {
        shapes_vector = {{' ', 'S', 'S'},
                         {'S', 'S', ' '}};
        break;
    }
    case shapes::Z:
    case shapes::z:
    {
        shapes_vector = {{'Z', 'Z', ' '},
                         {' ', 'Z', 'Z'}};
        break;
    }
    default:
    {
        cout << "Invalid tetromino" << endl;
        break;
    }
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
void Tetris::add(vector <vector<char>> tetromino){

    for (int i = 0; i < tetromino.size(); i++){
        for (int j = 0; j < tetromino[i].size(); j++){
              board[i+1][(width/2)+j-2] = tetromino[i][j];
         }
    }
}



void Tetris::scroll_tetros(vector <vector<char>> tetromino_vec,int row_count,char choice){
     
    for (int i = 0; i < tetromino_vec.size(); i++)
    {
        for (int j = 0; j < tetromino_vec[i].size(); j++)
        {    
            //checks if the next row is empty or not, if empty stop        
            if (board[row_count+3][(width/2)+j-1] != ' '  || board[row_count+3][(width/2)+j-2] != ' '  )  
                break;
            else
            {    
                //special conditions for L,I,J tetrominos 
                if (choice=='L' || choice=='l' )
                {
                    board[i+3+row_count][(width/2)+j-2] = tetromino_vec[i][j];
                    board[i+3+row_count][(width/2)+j-1] = tetromino_vec[i][j];
                    board[i+row_count][(width/2)+j-2] = ' ';
                    board[i+row_count+2][(width/2)+j-1] = ' ';
                }
                else if(choice=='J' || choice=='j'){
                    board[i+3+row_count][(width/2)+j-2] = tetromino_vec[i][j];
                    board[i+3+row_count][(width/2)+j-3] = tetromino_vec[i][j];
                    board[i+row_count][(width/2)+j-2] = ' ';
                    board[i+row_count+2][(width/2)+j-3] = ' ';
                }
                else if(choice =='I' || choice == 'i')
                {
                    board[i+3+row_count][(width/2)+j-2] = tetromino_vec[i][j];
                    board[i+2+row_count][(width/2)+j-2] = ' ';
                    board[i+1+row_count][(width/2)+j-2] = ' ';
                }
                else{
                    board[i+2+row_count][(width/2)+j-2] = tetromino_vec[i][j];//adds tetromino vector to the 2 line down
                    board[i+row_count][(width/2)+j-2] = ' ';//erase previously written tetromino to give animation effect
                }
            }
        }   
    }

}



 void Tetris::animate_pieces(vector <vector<char>> tetromino_vec,char choice){
    
   cout << "\x1b[0J"; //erase from cursor until end of screen
    cout<<"\x1b[s";  //save the cursor position

    add(tetromino_vec);//add tetromino vector to the one time in middle of the board

    for (int i = 1; i <= height-4; i=i+1){
        
        //draws,scrols and sleep one time then go back to saved position
        draw_board(); 
        scroll_tetros(tetromino_vec,i,choice);

        sleep(1);
        cout <<"\x1b[u";// go to saved cursor position
        
    }
    cout <<"\x1bM"; // cursor moves one line up
    
 }


 /*if we take the transpose of a matrix and then reverse the rows it will be rotated to right*/
void Tetromino::rotate(vector <vector<char>> will_transpose) const 
{
    transpose(will_transpose);
    reverse_vector(will_transpose);   
}


 void Tetromino::transpose( vector <vector<char>> will_transpose)const {
    
        int rows = will_transpose.size();
        int cols = will_transpose[0].size();
        vector<vector<char>> transposed_skeleton(cols, vector<char>(rows));/*declaring a vector for transposing*/

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            transposed_skeleton[j][i] = will_transpose[i][j];/*swapping rows and columns*/
        }
    }
    will_transpose = transposed_skeleton;
}


void Tetromino::swap(char* a, char* b) const
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//reversing the vector rows one by one 
void Tetromino::reverse_vector(vector<vector<char>> take_vec) const 
{
    for (int i = 0; i < take_vec.size(); i++) {
        int begin = 0;
        int end = take_vec[i].size() - 1;

        while (begin < end){
            swap(&take_vec[i][begin], &take_vec[i][end]);
            begin++;
            end--;
        }
    }
}

