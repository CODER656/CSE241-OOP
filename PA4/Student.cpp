#include "Student.h"
#include "Course.h"

using namespace PA4;

Student::Student() //Default constructer
{ 
    this->name = "";
    this->id = 0;
    this->course_ref = nullptr;
}


Student::Student(string name,int id)
{
    this->name = name;
    this->id = id;
    
}


Student::Student(const Student &other)
{
    name = other.name;
    id = other.id;
    course_ref = new Course[other.num_of_courses];//copy constructor
    num_of_courses = other.num_of_courses;

    for(int i = 0; i < num_of_courses; i++)
    {
        course_ref[i] = other.course_ref[i];
    }
}


Student &Student::operator=(const Student &other)
{
    if(this != &other)
    {
        delete [] course_ref;//deletes course_ref
        name = other.name;
        id = other.id;
        course_ref = new Course[other.num_of_courses];//copy constructor
        num_of_courses = other.num_of_courses;

        for(int i = 0; i < num_of_courses; i++)
        {
            course_ref[i] = other.course_ref[i];
        }
    }
    return *this;
}


int Student::getId()
{
    return id;
}


string Student::getName()
{
    return name;
}

int Student::getNumOfCourses()
{
    return num_of_courses;
}

void Student::setCourseRef(Course *course)
{
    this->course_ref = course;
}

void Student::setId(int id)
{
    this->id = id;
}


void Student::setName(string name)
{
    this->name = name;
}


void Student::setAll(string name, int id)
{
    this->name = name;
    this->id = id;
}



Course* Student::addCourse(Course *course)
{

    
    Course *temp = new Course[num_of_courses+1];//new array with one more element
    for (int i = 0; i < num_of_courses; i++)
    {
        temp[i] = course_ref[i];//copies course_ref to temp
    }
    temp[num_of_courses] = *course;//adds course to temp
    delete [] course_ref;//deletes  course_ref
    course_ref = temp;//course_ref is now temp
    num_of_courses++;//increases num_of_courses by 1
    return course_ref;//returns course_ref
}


//deletes course from course_ref inside student class 
bool Student::deleteCourse(Course *course)
{
    bool found = false;

    for (int i = 0; i < num_of_courses; i++)//checks if course is in course_ref
    {
        if (course_ref[i] == *course)//if course is in course_ref
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        if(num_of_courses == 0)
            return 0;
        else
        {
            int j=0;
            Course *new_arr = new Course[num_of_courses-1];//new array with one less element
            for (int i = 0; i < num_of_courses; i++)
            {
                if(course_ref[i] != *course)//copies course_ref to new_arr without course
                {
                    new_arr[j] = course_ref[i];//copies course_ref to new_arr without course
                    j++;
                }
            }
            delete[] course_ref;
            course_ref = new_arr;//course_ref is now new_arr
            num_of_courses--;   
        }
    }

    return found;
}


//prints the course_ref inside student class
void Student::print_course_ref()
{
    for (int i = 0; i < num_of_courses; i++)
    {
        cout << course_ref[i].getCode() << " " << course_ref[i].getName() << endl;//prints course_ref
    }
}

 



bool Student::operator==(const Student &other) const
{
    return (this->id == other.id) && (this->name == other.name);//checks if id and name are the same
}

bool Student::operator!=(const Student& other) const 
{
    return (this->id != other.id) && (this->name != other.name);//checks if id and name are not the same
}


Course* Student::getCourse(Course* course)
{
    for (int i = 0; i < num_of_courses; i++)
    {
        if (course->getCode() == course_ref[i].getCode());//checks if course is in course_ref
            return &course_ref[i];
    }
    
    return nullptr;
}


Student::~Student()//destructor
{
    delete [] course_ref;//deletes course_ref
    course_ref = nullptr;//sets course_ref to nullptr
}
