#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Pixel{ //Pixel class for holding rgb values of a pixel

    public:

        Pixel(): red(0),green(0),blue(0){} // default constructer initializes the rgb to 0
        Pixel(int r,int g,int b): red(r), green(g),blue(b){} // initializing private rgb data with constructer
        
        //getters and setters for rgb values
        const int& getRed() const {return red;}
        const int& getGreen() const {return green;}
        const int& getBlue() const {return blue;}

        void setRed(int r) {red = r;}
        void setGreen(int g) {green = g;}
        void setBlue(int b) {blue = b;}


    private:
        // RGB data
        int red; 
        int green;
        int blue;
};



class ppmImage{

    public:
         //A constructor which takes a ppm file name as argument and creates object form file.
        ppmImage(string fileName);

        //A constructor which creates an object according to the given dimensions. 
        //The image data should be allocated an initialized
        // in a way to represent a blank (white) image.
        ppmImage(int height,int width);

        //The default constructor
        ppmImage(){
            height = 0;
            width = 0;
        };


        //Accessor and mutator functions for private member data
        int getHeight() const { return height;}
        int getWidth() const { return width;}
        int getMaxColorValue() const { return maxColorValue;}

        void setHeight(int h) {height = h;}
        void setWidth(int w) {width = w;}
        void setMaxColorValue(int m) {maxColorValue = m;}

        //A member function in order to save ppm image to a file.
        void saveImage(const string fileName);

        //A member function to read ppm image from a file.
        void openImage(string fileName);

        //A member function which prints dimensions of the ppm image.
        void printDimensions();

        //A Member function which returns individual pixel information. This function will take some index value and
        //return information about the pixel pointed by that index for each color. (it basically takes a parameter and
        //according to that parameter, it returns red, green or blue value of that particular pixel)
        Pixel getPixel(int index) const ; 

        //Member functions which changes individual pixel values.
        void setPixel(int row, int col, int red, int green, int blue);
        void setPixelBySameVal(int row, int col, int color, int value);
        void setPixelByIndex(int index, int red, int green, int blue);

        //operator +: Adds two ppmImage objects. Adds them pixel-by-pixel. They have to be the same size otherwise
        //it returns an empty ppmImage object. (empty objects represents an image which has 0 number of pixels.).
        //1Color channels may reach to saturation. Don’t go beyond the max value written in the image data. You can
        //assume that both images will have the same max value.
        ppmImage operator+(ppmImage& other);

        //operator -: Similar to operator +. subtracts one image from the other. 
        //Color data cannot go below 0.
        ppmImage operator-(ppmImage& other);

        //operator <<: Prints image details and image data to stdout. 
        //This is similar to saving the image to a file. Allows cascading.
        friend ostream& operator<<(ostream& out, const ppmImage& image);

        //operator (): Function-call operator. This operator takes three parameters. The first parameter is the index
        //of the row number. The second parameter is the index of the column number. The third parameter is the
        //color channel. It can either 1, 2 or 3. The upper left corner is (0,0). This operator returns a reference to the
        //pixel value.
        const int& operator()(int row,int column,int color) const;
 

    private:

        int height; // height of the image
        int width; // width of the image
        int maxColorValue; // max color value of the image
        vector<Pixel> pixel; // vector of pixels which holds rgb values of each pixel

};

// returns 1 if the operation is successful. otherwise, returns 0.
// reads ppm data from file named as source_ppm_file_name. stores data in destination_object
//which is already created outside of the function.
int read_ppm(const string source_ppm_file_name, ppmImage& destination_object)
{
    destination_object.openImage(source_ppm_file_name); // open the file and read the data
    return 1;
}


// returns 1 if the operation is successful. otherwise, returns 0.
// writes ppm data from source_object to the file named destination_ppm_file_name.
int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object)
{
    ppmImage temp; // temporary object to hold the data
    temp = source_object; // copy the data from source object to temporary object
    temp.saveImage(destination_ppm_file_name); // save the data to the file

    return 1; // indicate success
}


// returns 1 if the operation is successful. otherwise, returns 0.
// reads images from filename_image1 and filename_image2. Adds them and saves the resulting
//image to filename_image3
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3)
{
    ppmImage editor1,editor2; // two editor objects

    editor1.openImage(filename_image1); // open the first image
    editor2.openImage(filename_image2); // open the second image

    ppmImage result = editor1 + editor2; // add the two images

    result.saveImage(filename_image3); // save the resulting image

    return 1; // indicate success
}


// returns 1 if the operation is successful. otherwise, returns 0.
// reads images from filename_image1 and filename_image2. Subtracts filename_image2 from
//filename_image1 saves the resulting image to filename_image3
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)
{
    ppmImage editor1,editor2;  // two editor objects

    editor1.openImage(filename_image1);
    editor2.openImage(filename_image2);

    ppmImage result = editor1 - editor2; // subtract the two images

    result.saveImage(filename_image3); // save the resulting image

    return 1; // indicate success
}


// returns 1 if the operation is successful. otherwise, returns 0.
// reads images from filename_image1 and prints it to stdout
int test_print(const string filename_image1)
{
    ppmImage editor1;   // one editor object

    editor1.openImage(filename_image1); // open the image

    cout << editor1; // print the image

    return 1; // indicate success
}

//fills the index of pixel vector  with the given values
void ppmImage::setPixelBySameVal(int row, int col, int color, int value)
{
    if (row < 0 || row >= height || col < 0 || col >= width || color < 0 || color > 3) // check if the given coordinates are valid
    {
        cerr << "Invalid pixel coordinates or color channel!\n";
        return;
    }
   
    // calculate the index of the pixel in the 1D array
    int index = row * width + col;

    if (index < 0 || index >= height * width) // check if the given coordinates are valid
    {
        cerr << "Invalid pixel indexinggg!\n";
        return;
    }

    // update the appropriate color channel of the pixel
    if (color == 1)
        pixel[index].setRed(value); // set red channel of pixel vector[index] which is an object of class Pixel
    else if (color == 2) 
        pixel[index].setGreen(value);
    else if (color == 3)
        pixel[index].setBlue(value);
}


// this function swaps the color values of every pixel in a given ppm image.
// this function does not create a new object but modifies the given one.
// if swap_choice is 1: swaps red and green
// if swap_choice is 2: swaps red and blue
// if swap_choice is 3: swaps green and blue
// if swap_choice is not 1, 2 or 3: no swaps (this does not mean that the operation is not
//successful. the function should return 1 in this case if everything is normal)
int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice)
{
    int height = image_object_to_be_modified.getHeight(); // get the height and width of the image
    int width = image_object_to_be_modified.getWidth();


    for (int i = 0; i < height; i++) // for each row
    {
        for (int j = 0; j < width; j++) // for each column
        {
            // red = 1, green = 2, blue = 3
            if (swap_choice == 1) //swap red and green
            {
                int green = image_object_to_be_modified(i, j, 2); // get green value of the pixel using overloaded operator()
                int red = image_object_to_be_modified(i, j, 1); // get red value of the pixel using overloaded operator()
                image_object_to_be_modified.setPixelBySameVal(i, j, 1, green); // set green value of the pixel using overloaded operator()
                image_object_to_be_modified.setPixelBySameVal(i, j, 2, red); // set red value of the pixel using overloaded operator()

            }
            else if (swap_choice == 2) //swap red and blue
            {
                int red = image_object_to_be_modified(i, j, 1);
                int blue = image_object_to_be_modified(i, j, 3);
                image_object_to_be_modified.setPixelBySameVal(i, j, 1, blue);
                image_object_to_be_modified.setPixelBySameVal(i, j, 3, red);
                
            }
            else if (swap_choice == 3) //swap green and blue
            {
                int green = image_object_to_be_modified(i, j, 2);
                int blue = image_object_to_be_modified(i, j, 3);
                image_object_to_be_modified.setPixelBySameVal(i, j, 2, blue);
                image_object_to_be_modified.setPixelBySameVal(i, j, 3, green);
            }
            else
                return 1;
        }
    }
        
    return 1;
}


// implement this using the function-call operator overloaded.
// creates and returns a copy of a new ppmImage object which stores only one color at each
//pixel. This simply takes the source and copies only one color information and stores it in
//a new object. The other color channels are simply going to be zeros.
//if color_choice is 1: red channel is preserved
//if color_choice is 2: green channel is preserved
//if color_choice is 3: blue channel is preserved
ppmImage single_color(const ppmImage& source, int color_choice)
{
    int height = source.getHeight(); // get the height and width of the image
    int width = source.getWidth();

    ppmImage result(height, width); // create a new image object

    for (int i = 0; i < height; i++) // for each row
    {
        for (int j = 0; j < width; j++) // for each column
        {
            if (color_choice == 1)  // preserve red channel
                result.setPixel(i, j, source(i, j, 1), 0, 0); // set red value of the pixel using overloaded operator() and everything else zero
            else if (color_choice == 2) // preserve green channel
                result.setPixel(i, j, 0, source(i, j, 2), 0); // set green value of the pixel using overloaded operator() and everything else zero
            else if (color_choice == 3)   // preserve blue channel
                result.setPixel(i, j, 0, 0, source(i, j, 3)); // set blue value of the pixel using overloaded operator() and everything else zero
        }
    }
    return result; // return the new image object
}

// this function sets the color values of a given pixel.
void ppmImage::setPixelByIndex(int index, int red, int green, int blue)
{
    if (index < 0 || index >= height * width) { // check if the given coordinates are valid
        cerr << "Invalid pixel index!\n";
        return;
    }

    pixel[index].setRed(red); //set the index of pixel vector using parameter
    pixel[index].setGreen(green); 
    pixel[index].setBlue(blue);
}

// this function sets the color values of a given pixel.
void ppmImage::setPixel(int row, int col, int red, int green, int blue)
{
    int index = row * width + col; // calculate the index of the pixel in the 1D array
    pixel[index].setRed(red);   //set the index of pixel vector using parameter
    pixel[index].setGreen(green);
    pixel[index].setBlue(blue);
}


// overloaded() for getting the color value of a pixel according to the given color
const int& ppmImage::operator()(int row, int col, int color) const
{
    int index = row * width + col; // calculate the index of the pixel in the 1D array

    if (color == 1) // if color is 1, return red value
        return pixel[index].getRed(); //return red value of the pixel 
    else if (color == 2) // if color is 2, return green value
        return pixel[index].getGreen(); //return green value of the pixel
    else if (color == 3) // if color is 3, return blue value
        return pixel[index].getBlue();  //return blue value of the pixel
    else    // if color is not 1, 2 or 3, return red value
        return pixel[index].getRed(); //return red value of the pixel
}

// constructer for opening a file for image
ppmImage::ppmImage(string fileName)
{
    openImage(fileName); // call openImage function
}

// constructer for creating a new image with given height and width
ppmImage::ppmImage(int height, int width)
{
    this->height = height; // set the height and width of the image
    this->width = width; 
    //allocate space
   pixel.resize(height*width);

    //initialize as a white image
    for (int i = 0; i < pixel.size(); i++) // for each pixel
    { 
        //make every pixel white
        pixel[i].setRed(255); 
        pixel[i].setGreen(255);
        pixel[i].setBlue(255);
    }
}

// member function for saving the image
void ppmImage::saveImage(const string fileName) 
{
    ofstream file; // file object
    file.open(fileName); //opens file with the file name that user entered

    // checking the if file opened
    if (!file.is_open()) {
        cerr << "Failed to open file " << fileName << endl;
        exit(1);
    }

    file << "P3\n"; // P3 format

    file << height << " " << width << endl; // Width and height
    file << maxColorValue << endl; // Max color value

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
}

// member function for opening the image
void ppmImage::openImage(string fileName)
{
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
    file >> maxColorValue;

    for (int i = 0; i < width * height; i++) // loop until file ends
    {
        int r, g, b;
        file >> r >> g >> b; // getting rgb values from file
        Pixel p(r, g, b); // initialing rgb values using parameterized constructer
        pixel.push_back(p); //storing the pixel in pixel vector 
    }

    file.close(); //closing the file
}

// prints the image dimensions
void ppmImage::printDimensions()
{
    cout << height << endl;
    cout << width << endl;
}

//gets pixel at index location
Pixel ppmImage::getPixel(int index) const
{
    return pixel[index]; //return the pixel at index location
}

// adds two images 
ppmImage ppmImage::operator+(ppmImage &other) // overloaded + operator
{
    if (this->height == other.height && this->width == other.width) // check if the images are same size
    {
        ppmImage image(this->height,this->width); // create a new image with same size

        for (int i = 0; i < pixel.size(); i++) // for each pixel
        {
            int red = this->pixel[i].getRed() + other.pixel[i].getRed(); // add red values of the two images
            int green = this->pixel[i].getGreen() + other.pixel[i].getGreen();
            int blue = this->pixel[i].getBlue() + other.pixel[i].getBlue();

            if (red > this->getMaxColorValue()) // if the red value is greater than max color value
                red = this->getMaxColorValue(); // set it to max color value

            if (green > this->getMaxColorValue())
                green = this->getMaxColorValue();

            if (blue > this->getMaxColorValue())
                blue = this->getMaxColorValue();

            image.setPixelByIndex(i, red, green, blue); // set the pixel in the new image
        }  
        return image; // return the new image
    }
    else
    {
        return ppmImage(); // return an empty image
    }
    
    return ppmImage(); // return an empty image
}

// subtracts two images
ppmImage ppmImage::operator-(ppmImage &other)
{
    if (this->height == other.height && this->width == other.width) // check if the images are same size
    {
        ppmImage image(this->height, this->width); // create a new image with same size

        for (int i = 0; i < pixel.size(); i++) // for each pixel
        {
            int red = this->pixel[i].getRed() - other.pixel[i].getRed(); // subtract red values of the two images
            int green = this->pixel[i].getGreen() - other.pixel[i].getGreen();
            int blue = this->pixel[i].getBlue() - other.pixel[i].getBlue();

            if (red < 0) // if the red value is less than 0
                red = 0; // set it to 0

            if (green < 0)
                green = 0;

            if (blue < 0)
                blue = 0;

            image.setPixelByIndex(i, red, green, blue); // set the pixel in the new image
        }
        return image; // return the new image
    }
    else
    {
        return ppmImage();  // return an empty image
    }

     return ppmImage(); // return an empty image
}


ostream &operator<<(ostream &out, const ppmImage &image)
{
    out << "P3\n"; // P3 format

    out << image.width << " " << image.height << endl; // Width and height
    out << image.maxColorValue; // Max color value

    for (int i = 0; i < image.pixel.size(); i++)
    {
        //writing pixels rgb data to file from vector
        out << image.pixel[i].getRed() << " ";
        out << image.pixel[i].getGreen() << " ";
        out << image.pixel[i].getBlue() << " ";
        out << "    ";
        if ((i + 1) % image.width == 0) //puts new line in every width ends
            out << endl;
    }

    return out;
}


int main(int argc, char *argv[])
{
    ppmImage image; // image object

    if (argc < 3) { // check if the number of command line arguments is valid
        cerr << "Error: invalid number of command line arguments" << endl;
        return 1;
    }

    // parse command line arguments
    int choice = atoi(argv[1]);
    string ppm_file_name1 = argv[2];
    string ppm_file_name2;
    string ppm_file_name3;
    
    if (argc >= 4)  
        ppm_file_name2 = argv[3]; 
    
    if (argc == 5) 
        ppm_file_name3 = argv[4];
    
    
    if (choice == 1)
        test_addition(ppm_file_name1, ppm_file_name2, ppm_file_name3);
    else if (choice == 2)
        test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3);
    else if (choice == 3)
    {
        read_ppm(ppm_file_name1,image); // reading the image file
        swap_channels(image,2); // swapping the channels in this case swapping red and blue
        write_ppm(ppm_file_name2,image);
    }
    else if (choice == 4 )
    {
        read_ppm(ppm_file_name1,image); // reading the image file
        swap_channels(image,3);// swapping the channels in this case swapping red and green    
        write_ppm(ppm_file_name2,image); // writing the image file
    }
    else if (choice == 5 )
    {
        read_ppm(ppm_file_name1,image); // reading the image file
        ppmImage image2 = single_color(image,1); // getting the single color image
        write_ppm(ppm_file_name2,image2); // writing the image file
    } 
    else if (choice == 6 )
    {
        read_ppm(ppm_file_name1,image);
        ppmImage image2 = single_color(image,2);
        write_ppm(ppm_file_name2,image2);
    }
    else if (choice == 7)
    {
        read_ppm(ppm_file_name1,image);
        ppmImage image2 = single_color(image,3);
        write_ppm(ppm_file_name2,image2);
    }

    return 0;
}


