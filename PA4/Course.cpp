#include "Course.h"
#include "Student.h"

using namespace PA4;

Course::Course()
{
    code = 0;
    name = "";
    student_ref = new Student[1];//default constructor
}

Course::Course(int code,string name)
{
    this->code = code;//constructor
    this->name = name;

}

Course::Course(const Course &other)
{
    code = other.code;
    name = other.name;
    student_ref = new Student[other.num_of_students];//copy constructor
    num_of_students = other.num_of_students;

    for(int i = 0; i < num_of_students; i++)
    {
        student_ref[i] = other.student_ref[i];
    }
}


Course& Course::operator=(const Course &other)
{
    if(this != &other)
    {
        delete [] student_ref;
        code = other.code;
        name = other.name;
        student_ref = new Student[other.num_of_students];
        num_of_students = other.num_of_students;
        for (int i = 0; i < num_of_students; i++)
        {
            student_ref[i] = other.student_ref[i];
        }
    }
    return *this;
}


int Course::getCode()
{
    return code;
}

string Course::getName()
{
    return name;
}

int Course::getNumOfStudents()
{
    return num_of_students;
}

Student *Course::getStudentRef()
{
    return student_ref;
}

void Course::setCode(int code)
{
    this->code = code;
}

void Course::setName(string name)
{
    this->name = name;
}


void Course::setAll(int code,string name)
{
    this->code = code;
    this->name = name;
}

void Course::setStudentRef(Student *student_ref)
{
    this->student_ref = student_ref;//it sets the student_ref that inside course class
}

void Course::setNumOfStudents(int num_of_students)
{
    this->num_of_students = num_of_students;//it sets the num_of_students that inside course class
}

Student* Course::getStudent(Student *student)
{
    for (int i = 0; i < num_of_students; i++)
    {
        if(studentExist(student))//it checks if the student exist in student_ref that inside course class
            return &student_ref[i];//it returns the student_ref that inside course class
    }
    return nullptr;
}


bool Course::studentExist(Student *student)
{
    for (int i = 0; i < num_of_students; i++)
    {
        if (student->getId() == student_ref[i].getId() && student->getName() == student_ref[i].getName())//it checks if the student exist in student_ref that inside course class
            return true;
    }
    return false;

}


Student* Course::getStudent(int id)
{
    for (int i = 0; i < num_of_students; i++) 
    {
        if (student_ref[i].getId() == id) //it checks if the student exist in student_ref that inside course class
            return &student_ref[i];
    }

    return nullptr;
}


//it adds the student to a student_ref that inside course class
void Course::addStudent(Student *student)
{
    if (num_of_students == 0)
    {
        student_ref = new Student[1];
        student_ref[0] = *student;
        num_of_students++;
    }
    else
    {
        Student *temp = new Student[num_of_students+1];//it creates a new student_ref that inside course class
        for (int i = 0; i < num_of_students; i++)
        {
            temp[i] = student_ref[i];//it copies the student_ref that inside course class to temp
        }
        temp[num_of_students] = *student;//it adds the student to temp
        num_of_students++;
        delete [] student_ref;
        student_ref = temp;

    }
}


//it deletes the student in student_ref that inside course class
bool Course::deleteStudent(Student *student)
{
     bool found = false;

    for (int i = 0; i < num_of_students; i++)//it checks if the student exist in student_ref that inside course class
    {
        if (student_ref[i] == *student)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        if(num_of_students == 0)
            return 0;
        else
        {
            int j=0;
            Student *new_arr = new Student[num_of_students-1];//it creates a new student_ref that inside course class
            for (int i = 0; i < num_of_students; i++)
            {
                if(student_ref[i] != *student)
                {
                    new_arr[j] = student_ref[i];
                    j++;
                }
            }
            delete[] student_ref;
            student_ref = new_arr;         
            num_of_students--;   
        }
    }

    return found;
}

//prints the student_ref inside course class
void Course::print_student_ref()
{
    for (int i = 0; i < num_of_students; i++)
    {
        cout << student_ref[i].getName() << " " << student_ref[i].getId() << endl;//it prints the student_ref that inside course class
    }
}


//prints the student_ref inside course class according to course code
void Course::print_student_ref_by_code(int code)
{
    
    for (int i = 0; i < num_of_students; i++)
    {
            cout << student_ref[i].getName() << " " << student_ref[i].getId() << endl;
    }
}


void Course::print_student_ref_by_course(Course *course)
{
    for (int i = 0; i < num_of_students; i++)
    {
        //if(student_ref[i].code == course->code)
            cout << student_ref[i].getName() << " " << student_ref[i].getId() << endl;
    }
}


bool Course::operator==(const Course &other) const
{
    return (this->code == other.code) && (this->name == other.name);
}

bool Course::operator!=(const Course &other) const
{
    return  (this->code != other.code) && (this->name != other.name);
}

Course::~Course()
{
    delete [] student_ref;
    student_ref = nullptr;
}


