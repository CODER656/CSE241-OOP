/*Furkan Taşkın 200104004072*/

#include <iostream>
#include "utils.h"
#include <vector>
using namespace std;

 //according to forms switches and creates tetrominos as a vector and send them to skeleton of tetrominos
 void Tetromino::make_forms_to_vector(forms form){

    switch (form){
        case forms::I:
        case forms::i:
        {
            skeleton = {{'I','I','I','I'}};
            break;
        }
        case forms::O:
        case forms::o:
        {
             skeleton = {{'O','O'},
                         {'O','O'}};
          
            break;
        }
        case forms::T:
        case forms::t:
        {
            skeleton= {{'T','T','T'},
                       {' ','T',' '}};
            break;
            }
        case forms::J:
        case forms::j:
        {
            skeleton = {{' ','J'},
                        {' ','J'},
                        {'J','J'}};
            break;
        }
        case forms::L:
        case forms::l:
        {
            skeleton = {{'L',' '},
                        {'L',' '},
                        {'L','L'}};
            break;
        }
        case forms::S:
        case forms::s:
        {
            skeleton = {{' ','S','S'},
                        {'S','S',' '}};
            break;
            }
        case forms::Z:
        case forms::z:
        {
            skeleton = {{'Z','Z',' '},
                        {' ','Z','Z'}};
            break;
            }
        default:{
            cout << "Invalid tetromino" << endl;
            break;
            }
    }
}
    
 //prints vector   
void Tetromino::print(vector < vector<char> >vec) const{
    
    for (int i=0; i<vec.size(); i++){
        for (int j=0; j<vec[i].size(); j++){
            cout << vec[i][j];
        }
        cout << endl;
    }
}

//prints skeleton of tetromino
void Tetromino::print() const{
    
    for (int i=0; i<skeleton.size(); i++){
        for (int j=0; j<skeleton[i].size(); j++){
            cout << skeleton[i][j];
        }
        cout << endl;
    }
}

bool Tetromino::check_user_input(char user_input) const{
    if (user_input == 'I' || user_input == 'O' || user_input == 'T' || user_input == 'J' || user_input == 'L' || user_input == 'S' || user_input == 'Z',
        user_input == 'i' || user_input == 'o' || user_input == 't' || user_input == 'j' || user_input == 'l' || user_input == 's' || user_input == 'z')
        return true;
    else
        return false;
}

/*if we take the transpose of a matrix and then reverse the rows it will be rotated to right*/
void Tetromino::rotate(vector <vector<char>> &will_transpose) const 
{
    transpose(will_transpose);
    reverse_vector(will_transpose);   
}


 void Tetromino::transpose( vector <vector<char>> &will_transpose)const {
    
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
void Tetromino::reverse_vector(vector<vector<char>> &take_vec) const 
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

Tetromino::Tetromino(forms f){//constructer

    skeleton = {{'T','T','T'},
               {' ','T',' '}};

}

//creating map with empty spaces,after that fill with tetrominos
void Tetromino::create_map(vector <vector<char>> &map,int width,int heigth){

    for (int i=0; i<map.size(); i++){
        for (int j=0; j<map[i].size(); j++){
            map[i][j] = ' ';
        }
    }
}


void Tetromino::print_map(vector <vector<char>> &map){
    
    for (int i=0; i<map.size(); i++){
        for (int j=0; j<map[i].size(); j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

 bool Tetromino::canFit(){
    
    create_map(map,skeleton.size(),skeleton[0].size());

      
    for (int i=0; i<skeleton.size(); i++){
        for (int j=0; j<skeleton[i].size(); j++){
            if (skeleton[i][j] != ' ' && map[i][j] != ' '){
                return false;
            }
        }
    }
    return true;

    print_map(map);


 }