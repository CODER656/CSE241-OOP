#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <unistd.h>
using namespace std;

namespace FurkanT{

enum class shapes{I = 'I',i = 'i' ,o = 'o' ,O = 'O', t = 't', T = 'T', j = 'j', J = 'J', l = 'l' ,L = 'L', s= 's' ,S = 'S', z = 'z', Z = 'Z'};


class Tetromino{
    public:
       
        Tetromino(shapes s); /*constructer with enum parameter*/
        Tetromino(){};

        ~Tetromino()
        {
            for (int i = 0; i < tet_row; i++)
                delete [] shapePtr[i];
            delete [] shapePtr;
        }

       shapes convert_shapes(char user_input) const {
            shapes shape = static_cast<shapes>(user_input); //converting char to forms enum type
            return shape;
        }


        void rotate(Tetromino & obj,int rot_dir,int rot_count) ;
        void transpose(Tetromino & tetro_obj) ;
        void reverse_array(Tetromino & obj);
        void swap(char* a, char* b) const;
        void tetro_reserve(char **&array,int dim1,int dim2);
         

        int get_tet_row() const { return tet_row; };
        int get_tet_col()const { return tet_col; };
        char **& get_shapePtr()  {return shapePtr;};
        void set_tet_row(int r){ tet_row = r;}
        void set_tet_col(int c){ tet_col = c;}

    
    
    private:

        char **shapePtr;
        int tet_row;
        int tet_col;
      
};



class Tetris{
 
  public:

    Tetris();
    Tetris(int height,int width);
    ~Tetris()
    {
        for (int i = 0; i < height; i++)
            delete [] board[i];
        delete [] board;
    }

      
    void resize(char **&array,int new_size,int size);
    void tetris_reserve(char **&array,int dim1,int dim2);
    void draw_board();
    void animate_pieces(char **shape,char choice,Tetromino & tetro,Tetris &tetris,int dir,int mv_cnt);
    void scroll_tetros(char **shape,int row_count,char choice,Tetromino &tet_obj,int dir,int mv_cnt);
    int  move(Tetromino & tet_obj,int direcion,int move_count);
    void clear();


    //adds tetromino to middle of the board
    Tetris & operator+=(Tetromino & tet_obj)
    { 
        for (int i = 0; i < tet_obj.get_tet_row(); i++){
            for (int j = 0; j < tet_obj.get_tet_col(); j++){
                board[i+1][(width/2)+j-2] = tet_obj.get_shapePtr()[i][j];
            }
        }
            return *this;
    }

    
  
  
  private:

      char **board;
      int width;
      int height;
};


}

























#endif