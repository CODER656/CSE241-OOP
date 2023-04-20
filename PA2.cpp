#include <iostream>
#include <vector>
#include <string>
#include <fstream> // for file inputting and outputting

using namespace std;


class Pixel{ //Pixel class for holding rgb values of a pixel

    public:

        Pixel(): red(0),green(0),blue(0){} // default constructer initializes the rgb to 0
        Pixel(int r,int g,int b): red(r), green(g),blue(b){} // initializing private rgb data with constructer
        
        //getters and setters for rgb values
        int getRed() {return red;}
        int getGreen() {return green;}
        int getBlue() {return blue;}

        void setRed(int r) {red = r;}
        void setGreen(int g) {green = g;}
        void setBlue(int b) {blue = b;}


    private:
        // RGB data
        int red; 
        int green;
        int blue;
};


class ImageEditor{ // Class for editor program

    public:
        ImageEditor(); // default constructer

        //getters and setters for height and width
        int getHeight() { return height;}
        int getWidth() { return width;}

        void openImage(); // opens a ppm file 
        void saveImage(); // saves changes to ppm file 
        int convertToGrayScale(); // converts pixels to gray scale 




    private:
        vector<Pixel> pixel; // Pixel class vector for storing data that read from file
        int height; // height and width of the ppm file, these are read from file
        int width;


};




ImageEditor::ImageEditor()// default constructer
{
}



//If user enters 1, then user can enter a filename.
void ImageEditor::openImage()
{
    int input = -1; 

    while(input != 0) // while user doesn't press 0 
    {
        cout << "OPEN AN IMAGE MENU\n"; //menu items
        cout << "0 - UP\n";
        cout << "1 - Enter The Name Of The Image File\n";

        cin >> input; // getting the choice input from user
        if (input == 1) // user presses 1
        {
            string fileName; 
            cin >> fileName; // getting file name for which file will be open

            //- create an image object
            //- read ppm image data
            //- store image data in the image object
            ifstream file; //file object
            file.open(fileName); //opens file with the file name that user entered

            // Read the file format, width and height values
            string file_format;
            file >> file_format >> width >> height;


            // Check if the magic number is P3 and the width and height values are valid
            if (file_format != "P3" || width <= 0 || height <= 0) {
                cerr << "Error: invalid file format" << endl;
                file.close();
                return;
            }

            // Read the max color value
            int maxColorValue;
            file >> maxColorValue;

            for (int i = 0; i < width * height; i++) // loop until file ends
            {
                int r, g, b;
                file >> r >> g >> b; // getting rgb values from file
                Pixel p(r, g, b); // initialing rgb values using parameterized constructer
                pixel.push_back(p); //storing the pixel in pixel vector 
            }

            file.close(); //closing the file
            continue; // for printing the same menu again
        }
        
    }


}


//If user enters 1, then user can enter a filename. 
//Example: Assume user enters output.ppm. In this case, image data
//in the memory will be saved as output.ppm.
void ImageEditor::saveImage()
{
    int input = -1;

    while(input != 0)   // while user doesn't press 0 
    {
        cout << "SAVE IMAGE MENU\n"; //menu items
        cout << "0 - UP\n";
        cout << "1 - Enter A File Name\n";

        cin >> input; // getting the choice input from user
        if (input == 1) // if users enters 1
        {
            string fileName;
            cin >> fileName; //getting the file name for saving
            
            ofstream file; // file object
            file.open(fileName); //opens file with the file name that user entered

            // checking the if file opened
            if (!file.is_open()) {
                cerr << "Failed to open file " << fileName << endl;
                continue;
            }

            file << "P3\n"; // P3 format

            file << width << " " << height << endl; // Width and height
            file << "255\n"; // Max color value

            for (int i = 0; i < pixel.size(); i++)
            {
                //writing pixels rgb data to file from vector
                file << pixel[i].getRed() << " ";
                file << pixel[i].getGreen() << " ";
                file << pixel[i].getBlue() << " ";
                file << "    ";
                if( (i+1) % width == 0) //puts new line in every width ends
                   file << endl;
            }

            file.close(); // closing the file


            continue; // for printing same menu again
        }
    }
}

//converts images to gray scale version
int ImageEditor::convertToGrayScale()
{
    int script_input = -1; // for script menu input
    int coef_input = -1; // for coefficients menu input
    float c_r, c_g, c_b; // for coefficients that will be entered from user

    while(script_input != 0) // if user enters 0 it goes previous menu
    {
        cout << "SCRIPTS MENU\n"; // menu items
        cout << "0 - UP\n";
        cout << "1 - Convert To Grayscale(D)\n";

        cin >> script_input; // gettin input from user

        if (script_input == 1) 
        {
            coef_input = -1; // for menu movements 

            while (coef_input != 0)
            {
                cout << "CONVERT TO GRAYSCALE MENU\n";
                cout << "0 - UP\n";
                cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels.\n";

                cin >> coef_input; // getting what will user do

                 if (coef_input == 1)
                {
                    cin >> c_r >> c_g >> c_b; //it should be between [0,1)
                    while (c_r < 0 || c_r >= 1 || c_g < 0 || c_g >= 1 || c_b < 0 || c_b >= 1) // if users not enters proper inputs asks again 
                    {
                        cout << "Coefficients should be between [0,1). Please enter again: ";
                        cin >> c_r >> c_g >> c_b;
                    }
                    //implement gray scale with formula:
                    // RED = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
                    //GREEN = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
                    //BLUE = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
                    for (int i = 0; i < pixel.size(); i++)
                    {
                        // getting rgb values from vector
                        int r = pixel[i].getRed();
                        int g = pixel[i].getGreen();
                        int b = pixel[i].getBlue();

                        // calculating gray scale value
                        int gray = (c_r * r) + (c_g * g) + (c_b * b);

                        // setting new rgb values to vector
                        pixel[i].setRed(gray);
                        pixel[i].setGreen(gray);
                        pixel[i].setBlue(gray);
                    }
                    continue;
                }
            }
        }
    }
    return 0;
}




int main(int argc, char const *argv[])
{
    int input = -1; // for user input

    ImageEditor editor; // object of ImageEditor class
 
    while(input != 0)
    {
        cout << "MAIN MENU\n"; //printing main menu items
        cout << "0 - Exit\n";
        cout << "1 - Open An Image(D)\n";
        cout << "2 - Save Image Data(D)\n";
        cout << "3 - Scripts(D)\n";

        cin >> input; // getting input from user for main menu

        switch (input) // switching between menus
        {
            case 1:
                editor.openImage(); // user want to open an image file so called member function
            break;
                

            case 2:
                editor.saveImage(); // calling member function for saving the image
            break;
            

            case 3:
                editor.convertToGrayScale(); // calling member function for converting gray scale version
            break;
        }

    }


    return 0;
} // end main



