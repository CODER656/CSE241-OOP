/*Furkan Taşkın 200104004072*/

#include <iostream>
#include "utils.h"
#include <vector>


using namespace std;

int main(){

    char user_input;
    int limit;
    Tetromino tetromino;
    bool end;

    cout << "How many tetrominominos do you want to create? ";
    cin >> limit;

    vector <Tetromino> tetroList(limit);


    cout<< "Select from: I,i,O,o,T,t,J,j,L,l,S,s,Z,z"<< "\n";

     // get tetromino form from user until limit of tetrominos is reached
    for (int i=0; i<limit; i++){
         cout << "Enter a tetromino: ";
         cin >> user_input;
         end=tetromino.check_user_input(user_input); //if input is wrong it will terminate the program
         if(end==false)
            return -1;
         tetromino.make_forms_to_vector(tetromino.set_form(user_input));//converting char input to forms enum then sending to funtion
         tetroList[i].skeleton = tetromino.skeleton;//vector in class equals to class vector's skeleton vector
    }

     //printing tetrominos
    cout << "\n" << "Your tetrominos are:" << "\n";
    for (int i=0; i<tetroList.size(); i++){
         tetroList[i].print(); 
         cout << "\n"; 
    }
  
    
    cout<< "Rotated:"<< "\n";
    for (int i=0; i<tetroList.size(); i++){
         tetromino.rotate(tetroList[i].skeleton);//sending vector to function for to rotate it
         tetroList[i].print();
         cout << "\n";
     }


    //This function gives seg fault so i don't use it
    cout<< "Horizantally best-fit tetrominos:"<<"\n";
     for (int i=0; i<tetroList.size(); i++){
           //tetromino.canFit();
           //tetroList[i].print();
           cout << "\n";
      }

     /*canFit function is not a full function. Fortunately i have the algorithm idea.
       We have the width and height property. If width and height values are not the same that means we have a empty space.
       Since it is a Tetromino we know where that empty space is. If two tetrominos empty space are matches that means we can fit them
       */
    //I nearly spent 50 hours for this homework
    
    return 0;

}



