/*Furkan Taşkın 200104004072 CSE241 Homework 1*/
#include <iostream>
#include <cstdlib>


using namespace std; //standart namespace

int  rand_num(int digit_num); // creates random number by parameter long
bool compare(const char * str1,int size1, const char * str2, int size2); // compares two strings if equal returns true
int  length(const char *str); //gives length of a string
bool repeating(const char* str ); //finds if a character is repeating in a string
bool valid_secret_num(const char *str); // validates the number that generated in the program
int  exact_count(const char *secret , const char *proposed); //The count of digits of the proposed number that match in place of the secret number. 
int  misplaced_count(const char *secret , const char *proposed); // The count of digits of the proposed number which do exist in the secret number but are not in place.
char * int_to_string(int num); //converts integers to strings
bool contains_char(const char* str); // finds given string has a character like 'b' or '?'


int main(int argc, char* argv[])
{
    const int MAX_GAME_COUNT = 100;
    const int MAX_DIGIT_NUM = 10;
    int game_count = 1,digit_num,rand_number;
    char proposed[MAX_DIGIT_NUM]; //Character array for receiving guesses from user
    bool found = false; //flag control for user found the number or not
    



    if (compare(argv[1],length(argv[1]),"-r",length("-r"))) //user enters the "-r" command or not 
    {
        digit_num = atoi(argv[2]); //converting second argument to int
        if (digit_num < 0 || digit_num == 0) //if second argument is negative or 0 exit
        {
            cout << "E0" << endl;
            return 0;
        }
        
        rand_number = rand_num(digit_num); //generating the random number which will be secret number
    }
    else if (compare(argv[1],length(argv[1]),"-u",length("-u"))) // user will enter the secret number as an argument
    {
        if (repeating(argv[2])) //if user command line argument repeats
        {
            cout << "E0" << endl;  //print error and exit
            return 0;
        }
    }
    else //if user not enters -u or -r
    {
        cout << "E0" << endl;
        return 0;
    }



    while(game_count <= MAX_GAME_COUNT && !found) //game loop until 100(MAX_GAME_COUNT) and user founds the secret number
    {
        if (argc == 3) // if 3 command line argument entered
        {
            if ( valid_secret_num( int_to_string(rand_number)) ) //validating random number but first converting to string because function accepts string
            {
                cin >> proposed; //getting user guesses
                if (digit_num != length(proposed)) //user enters different length other than digit number that number suppose to have
                {
                    cout << "E1" << endl;
                    return 0;
                }                
                if (repeating(proposed)) //if user guesses are repeating
                {
                    cout << "E0" << endl;
                    return 0;
                }
                if (contains_char(proposed)) //if user guesses are contains other than digits [0-9]
                {
                    cout << "E2" << endl;
                    return 0;
                }

                
                //if user founds the secret number
                if (compare(int_to_string(rand_number),length(int_to_string(rand_number)),proposed,length(proposed))) //here function calls to match parameter type
                {
                    found = true;
                    cout << "FOUND " << game_count;
                    return 0;
                }
                //printing counts to screen
                cout << exact_count(int_to_string(rand_number),proposed) << " ";
                cout << misplaced_count(int_to_string(rand_number),proposed) << endl;


                
            }


        

            if ( compare(argv[1],length(argv[1]),"-u",length("-u")) && valid_secret_num(argv[2]) ) // for -u option
            {
                cin >> proposed; //user enters guesses

                if (repeating(proposed)) // if guesses repeats
                {
                    cout << "E0" << endl;
                    return 0;
                }
                if (contains_char(proposed)) // if guesses contains other than digits[0-9]
                {
                    cout << "E2" << endl;
                    return 0;
                }

                
                
                if (compare(argv[2],length(argv[2]),proposed,length(proposed))) //if user founds the secret number in -u option
                {
                    found = true; //found is true now
                    cout << "FOUND " << game_count;
                    return 0;
                }
                //printing counts to screen
                cout << exact_count(argv[2],proposed) << " ";
                cout << misplaced_count(argv[2],proposed) << endl;
            }





        }
        else //if user enter different numbers of parameters
        {
            cout << "E0" << endl;
        }


     game_count++; //increment the counts in the game

     if (game_count == MAX_GAME_COUNT) //if user cannot find in 100 trials game ends with failure
     {
        cout << "FAILED";
        return 0;
     }
     

    }//end while



    return 0;
}//end main



//creates random number by digit number long
int rand_num(int digit_num)
{
    srand(time(NULL)); //time seed
    int rand_number = 0;

    do {
        rand_number = 0; //starting zero again 
        for (int i = 0; i < digit_num; i++) //until number of digits that secret number has
        {
            rand_number = rand_number * 10 + rand() % 10; //creates random number and adds itself by multiplying 10 
        }
    } while (repeating(int_to_string(rand_number))); //until number don't repeat

    return rand_number; //returns random number
}



// my function to compare two strings
bool compare(const char *str1, int size1, const char *str2, int size2)
{
    if (size1 != size2) //if sizes are not equal strings cannot be equal
        return false;

    for (int i = 0; i < size1; i++)
    {
        if (str1[i] != str2[i]) //comparing every char
            return false; // if one of them are not eqaul returns false
    }

    return true; //else returns false

}


//returns lenght of the array
int length(const char *str)
{
    int i=0;

    while (str[i] != '\0') //until end of string (c strings has NULL in the end)
        i++; //increment count

    return i;
}


//checks is digits is repeating in the number
bool repeating(const char* str )
{    
    for (int i = 0; i < length(str) - 1; i++) //nested for loop
    {
        for (int j = i + 1; j < length(str); j++) //j starts from where i left off
        {
            if (str[i] == str[j]) //checking array for every element but avoid comparing itself
                return true; 
        }
    }
    
    return false;
}


// validating secret number function
// leftmost digit can not be 0
// digit can not be repeat
bool valid_secret_num(const char *str)
{
    if(length(str) > 9) //length of number cannot be more than 9
        return false;

    if (str[0] == '0')// cannot start with 0
        return false;

    if (repeating(str))//cannot repeat any digit
        return false;

    return true;
}



// function for converting int to C string
char * int_to_string(int num)
{
    static char string[10]; // allocate a string for the string representation
    int i = 0;

    do
    {
        string[i++] = num % 10 + '0'; // add the least significant digit to the string
        num /= 10; // remove the least significant digit from the number
    
    } while (num > 0);

    string[i] = '\0'; // put null character at the end of the string

    // reverse the string in place
    for (int j = 0; j < i / 2; j++) 
    {
        char temp = string[j]; 
        string[j] = string[i - j - 1];
        string[i - j - 1] = temp;
    }



    return string;

}


//checks if a string has a char other than that digits
bool contains_char(const char* str){

    bool contains_char = false;

    for (int i = 0; i < length(str); i++) //until lenght of that string
    {
        if (str[i] < '0' || str[i] > '9') //if string has different chars
            contains_char = true; //means it has chars other than digits
    }

    return contains_char;

}



//function to determine The count of digits of the proposed number 
//that match in place of the secret number.
int exact_count(const char *secret , const char *proposed)
{
    int count = 0;
    
    for (int i = 0; i < length(secret); i++)
    {
        for (int j = 0; j < length(proposed); j++)
        {
            if (secret[i] == proposed[j] && i == j)//checks if element in place and should exist in the secret number
                count++; // if existed and in place increment count
        }
        
    }

    return count;
}



//Second count (Cmisplaced ): The count of digits of the proposed 
//number which do exist in the secret number but are not in place.
int misplaced_count(const char *secret , const char *proposed)
{
    int count = 0;

    for (int i = 0; i < length(secret); i++)
    {
        for (int j = 0; j < length(proposed); j++)
        {
            if (secret[i] == proposed[j] && i != j)//exist but not in place
                count++;
        }
    }

    return count;
}








