#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <vector>
#include <unistd.h>



using namespace std;

enum class shapes{I = 'I',i = 'i' ,o = 'o' ,O = 'O', t = 't', T = 'T', j = 'j', J = 'J', l = 'l' ,L = 'L', s= 's' ,S = 'S', z = 'z', Z = 'Z'};


class Tetromino{
    public:
       
        Tetromino(shapes s); /*constructer with enum parameter*/
        Tetromino(){};

       shapes set_shapes(char user_input) const {
            shapes shape = static_cast<shapes>(user_input); //converting char to forms enum type
            return shape;
        }
     
      vector < vector <char>> get_shape_vector(){
           return shapes_vector;
        }

        void rotate(vector <vector<char>> will_transpose) const;
        void transpose(vector <vector<char>> vec) const;
        void reverse_vector(vector<vector<char>> take_vec) const;
        void swap(char* a, char* b) const;
         

        int get_width() const { return width; }
        int get_height()const { return height; }
        void set_width(int w){ width = w;}
        void set_height(int h){ height = h;}
    
    
    private:
         vector < vector <char>> shapes_vector;
         int width;
         int height;
      
};





class Tetris{
 
  public:
      Tetris();
      Tetris(int width,int height);
      
      void draw_board();
      void draw_board(int count_row);   
      void check_user_input();
      void add(vector <vector<char>> tetromino);
      void animate_pieces(vector <vector<char>> tetromino_vec,char choice);
      void scroll_tetros(vector <vector<char>> tetromino_vec,int row_count,char choice);
  
  
  private:

      vector < vector <char>> board;
      vector < vector <char>> shapes_vector;
      int width;
      int height;
};



#endif
