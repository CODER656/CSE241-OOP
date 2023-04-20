#include <iostream>
#include <list>

using namespace std;


namespace FurkanT{

 
class DayofYearSet{
    
    public:

       class DayofYear{

           public:
              
            DayofYear();
            DayofYear(int day, int month);
            DayofYear(const DayofYear & doy_obj);

            int get_day() const {return day;};
            int get_month() const {return month;};

            //overloaded assingment operator
            DayofYear& operator=(const DayofYear& inp);

            //overloaded != operator
            bool operator!=(const DayofYear& inp) const;

            //overloaded == operator
            bool operator==(const DayofYear& inp) const;

            //overloaded << operator
           friend ostream & operator<< (ostream &output,const DayofYear& inp);


                 
           private:
               int day;
               int month;

            
       }; //end of DayofYear



    DayofYearSet(){};

    //Has a list initializer constructor that takes lists such as {d1, d2, d3}, 
    //where d’s are DayOfYear objects.
    DayofYearSet(initializer_list <DayofYear> days);  

    ~DayofYearSet();

    //getter for doy_el
    DayofYear* get_doy_el() const {return doy_el;};

    int size()const {return doys_size;};     

    // remove removes an element from the set.
    void remove(const DayofYear& inp);


    friend ostream & operator<< (ostream &out,const DayofYearSet& inp);

    //Overloaded operator== and operator!= operators for comparing DayofYearSet objects. Two
    //sets are equal if their elements are equal regardless of the keeping order.
    bool operator==(const DayofYearSet& inp) const;
    bool operator!=(const DayofYearSet& inp) const;


    //Overloaded binary operator+ adds an element to the set. 
    //Please note that no duplicates are allowed in a set
    DayofYearSet& operator+(const DayofYear& inp);

    //Overloaded binary operator+ returns the union set.
    DayofYearSet operator+(const DayofYearSet& inp) const;

    //Overloaded binary operator- returns the difference set.
    DayofYearSet operator-(const DayofYearSet& inp) const;

    //Overloaded binary operator- removes an element from the set.
    DayofYearSet& operator-(const DayofYear& inp);

    //Overloaded binary operator^ returns the intersection set.
    DayofYearSet operator^(const DayofYearSet& inp) const;

    //Overloaded unary operator! returns the complement set. Note that there may be 365 days in a year.
    DayofYearSet operator!() const;

    //Overloaded binary operator[] returns the element at given position.
    DayofYear operator[](int pos) const;

    //seperates test blocks
    void seperator() const;





    

    private:  //for outsider class
         
        DayofYear *doy_el;
        int doys_size;

};






}





