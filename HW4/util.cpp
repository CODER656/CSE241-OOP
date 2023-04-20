
#include "util.h"

namespace FurkanT{

DayofYearSet::DayofYear::DayofYear() 
{
    day = 1;
    month = 1;
}


DayofYearSet::DayofYear::DayofYear(int d, int m) {
       
    int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    if (d > months[m-1] || d < 1 || m > 12 || m < 1) 
        throw invalid_argument("Invalid day or month");

        day = d;
        month = m;

}


DayofYearSet::DayofYear::DayofYear(const DayofYear & doy_obj){

    day = doy_obj.day;
    month = doy_obj.month;
}




//overloaded assingment operator for DayofYear
DayofYearSet::DayofYear&  DayofYearSet::DayofYear::operator=(const DayofYear& inp){

    if (this == &inp)
        return *this;

    day = inp.day;
    month = inp.month;

    return *this;

}


//overloaded != operator for DayofYear
bool DayofYearSet::DayofYear::operator!=(const DayofYear& inp) const{
    
        if (day != inp.day || month != inp.month)
            return true;
        else
            return false;
    

}





//Has a list initializer constructor that takes lists such as {d1, d2, d3}, 
//where d’s are DayOfYear objects.
DayofYearSet::DayofYearSet(initializer_list <DayofYear> day_list) {

        // Set the size of the array
        doys_size = day_list.size();

        // Allocate memory for the DayOfYear objects
        doy_el = new DayofYear[day_list.size()];

        // Copy the DayOfYear objects from the initializer list
        int i = 0;
        for (DayofYear doy : day_list) {
            doy_el[i] = doy;
            i++;
        }

}


DayofYearSet:: ~DayofYearSet() 
{
    delete[] doy_el;
    doy_el = nullptr;
}



//removes an element from the set.
void DayofYearSet:: remove(const DayofYear& inp){

 // Check if the input DayofYear object is in the set
    bool found = false;
    for (int i = 0; i < doys_size; i++) {
        if (doy_el[i] == inp) {
            found = true;
            break;
        }
    }

    if (!found) return;

    // Create a new array with one less element
    DayofYear* temp = new DayofYear[doys_size - 1];

    // Copy the elements from the old array to the new one
    int j = 0;
    for (int i = 0; i < doys_size; i++)
     {
        if (doy_el[i] != inp) 
        {
            temp[j] = doy_el[i];
            j++;
        }
    }


    doy_el = temp;

    doys_size--;
}


//Overloaded binary operator+ adds an element to the set. 
//Please note that no duplicates are allowed in a set
DayofYearSet&  DayofYearSet:: operator+(const DayofYear& inp) {

    // check if the element is already in the set
    for (int i = 0; i < doys_size; i++) 
    {
        if (doy_el[i] == inp)
            return *this;
    }

    // create a new array with one more element
    DayofYear* temp = new DayofYear[doys_size + 1];

    // copy the elements from the old array to the new one
    for (int i = 0; i < doys_size; i++) 
    {
        temp[i] = doy_el[i];
    }

    // add the new element to the new array
    temp[doys_size] = inp;


    // assign the new array to the old array
    doy_el = temp;

    // increase the size of the array
    doys_size++;

    return *this;
}       


//Overloaded operator== operator for comparing DayofYearSet objects. Two
//sets are equal if their elements are equal regardless of the keeping order.
bool DayofYearSet::operator==(const DayofYearSet& inp) const {
  
    // check if the sizes of the two sets are different
    if (this->doys_size != inp.doys_size)
        return false;

    // check if the elements of the two sets are different
    for (int i = 0; i < this->doys_size; i++) 
    {
        if (this->doy_el[i] != inp.doy_el[i]) 
            return false;
    }

    // if the sizes are the same and all the elements are the same, the sets are equal
    return true;
}


//Overloaded operator!= operator for comparing DayofYearSet objects.
bool DayofYearSet::operator!=(const DayofYearSet& inp) const {
    return !(*this == inp);
}


//overloaded == operator for DayofYear
bool DayofYearSet::DayofYear::operator==(const DayofYear& inp) const{

    if (day == inp.day && month == inp.month)
        return true;
    else
        return false;

}


//Overloaded binary operator[] returns the element at given position.
DayofYearSet::DayofYear DayofYearSet::operator[](int pos) const {

    if (pos >= 0 && pos < doys_size) 
        return doy_el[pos];
    else 
        throw out_of_range("Invalid position");

}


//Overloaded friend stream insertion operator operator<< will print DayofYearSet details.
ostream& operator<<(ostream& out, const DayofYearSet& inp) {
   //namespace adını ekle operator<< dan önce
    out << "{";
    for (int i = 0; i < inp.size(); i++) 
    {
        out << inp.get_doy_el()[i];
        if (i < inp.size() - 1)
            out << ", ";
    }
    out << "}";

    return out;
}


//Overloaded friend stream insertion operator operator<< will print DayofYear details.
ostream& operator<<(ostream& output, const DayofYearSet::DayofYear& inp) {

    output << inp.get_day() << "/" << inp.get_month();

    return output;
}


//Overloaded binary operator+ returns the union set.
DayofYearSet DayofYearSet:: operator+(const DayofYearSet& inp) const{

    DayofYearSet temp = *this;
    
    for (int i = 0; i < inp.size(); i++) 
    {
        temp = temp + inp.get_doy_el()[i];
    }
   
    return temp;
     
}



//Overloaded binary operator- returns the difference set.
DayofYearSet DayofYearSet:: operator-(const DayofYearSet& inp) const{

    DayofYearSet temp = *this;

    for (int i = 0; i < inp.size(); i++) 
    {
        temp = temp - inp.get_doy_el()[i];
    }

    return temp;
    
}


//Overloaded binary operator- removes an element from the set.
DayofYearSet& DayofYearSet:: operator-(const DayofYear& inp) {

    // check if the element is in the set
    for (int i = 0; i < doys_size; i++) 
    {
        if (doy_el[i] == inp) 
        {
            // create a new array with one less element
            DayofYear* temp = new DayofYear[doys_size - 1];

            // copy the elements from the old array to the new one, skipping the element that needs to be removed
            int j = 0;
            for (int i = 0; i < doys_size; i++) 
            {
                if (doy_el[i] != inp) 
                {
                    temp[j] = doy_el[i];
                    j++;
                }
            }


            doy_el = temp;

            // decrease the size of the array
            doys_size--;

            return *this;
        }
    }

    return *this;


}


//Overloaded binary operator^ returns the intersection set.
DayofYearSet DayofYearSet:: operator^(const DayofYearSet& inp) const{

    DayofYearSet temp;

    for (int i = 0; i < this->size(); i++) 
    {
        for (int j = 0; j < inp.size(); j++) 
        {
            if (this->get_doy_el()[i] == inp.get_doy_el()[j]) 
            {
                temp = temp + this->get_doy_el()[i];
            }
        }
    }

    return temp;
    

}


//Overloaded unary operator! returns the complement set. Note that there may be 365 days in a year.
DayofYearSet DayofYearSet:: operator!() const{

    int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    DayofYearSet complement;
    for (int m = 1; m <= 12; m++) {
        for (int d = 1; d <= months[m-1]; d++) {
            DayofYear doy(d, m);
            bool found = false;
            for (int i = 0; i < doys_size; i++) {
                if (doy_el[i] == doy) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                complement = complement + doy;
            }
        }
    }
    return complement;
}

    



//prints =
void DayofYearSet::seperator() const {
    cout << "============================================" << endl;
}


}