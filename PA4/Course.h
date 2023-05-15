#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Student.h"



using namespace std;

namespace PA4{

class Student;

class Course
{
    public:

        Course();
        Course(int code,string name);
        Course(const Course &other);
        Course& operator=(const Course &other);

        int getCode();
        string getName();
        int getNumOfStudents();
        Student* getStudentRef();
        

        void setCode(int code);
        void setName(string name);
        void setAll(int code,string name);
        void setStudentRef(Student *student_ref);
        void setNumOfStudents(int num_of_students);

        Student* getStudent(Student *student);
        Student* getStudent(int id);
        void addStudent(Student *student);
        bool deleteStudent(Student *student);
        bool studentExist(Student *student);
        void print_student_ref();
        void print_student_ref_by_code(int code);
        void print_student_ref_by_course(Course *course);
    

        bool operator==(const Course& other) const;
        bool operator!=(const Course& other) const;

        ~Course();




    private:
        int code;
        string name;
        Student *student_ref;
        int num_of_students=0;



};



}

#endif