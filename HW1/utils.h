/*Furkan Taşkın 200104004072*/

#include <iostream>
#include <vector>

enum class forms{I = 'I',i = 'i' ,o = 'o' ,O = 'O', t = 't', T = 'T', j = 'j', J = 'J', l = 'l' ,L = 'L', s= 's' ,S = 'S', z = 'z', Z = 'Z'};

using namespace std;


// write forms as a vectors
class Tetromino{
    public:

        forms set_form(char user_input) const {
            forms form = static_cast<forms>(user_input); //converting char to forms enum type
            return form;
        }

        void make_forms_to_vector(forms form);
       
        Tetromino(forms f); /*constructer with enum parameter*/
        Tetromino(){};
      
        void print() const;
        void print(vector < vector<char> >vec) const;
    

        bool check_user_input(char user_input) const;
        vector < vector<char>> skeleton;  

        void rotate(vector <vector<char>> &will_transpose) const;
        void transpose(vector <vector<char>> &vec) const;
        void reverse_vector(vector<vector<char>> &take_vec) const;
        void swap(char* a, char* b) const;
         

        bool canFit();

        int get_width() const { return width; }
        int get_height()const { return height; }
        void set_width(int w){ width = w;}
        void set_height(int h){ height = h;}


        vector < vector<char>> map; 
        //create map for printing tetrominos side by side
        void create_map(vector <vector<char>> &map,int width,int heigth);
        //print map
        void print_map(vector <vector<char>> &map);
    
    
    private:
         int width;
         int height;
      
};