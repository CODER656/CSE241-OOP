#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Course.h"



using namespace std;

namespace PA4{

class Course;

class Student{

    public:
        Student();

        Student(string name,int id);
        Student(const Student &other);
   
        Student& operator=(const Student &other);


        int getId();
        string getName();
        int getNumOfCourses();
        Course* getCourseRef();
        void setCourseRef(Course* course);

        void setId(int id);
        void setName(string name);
        void setAll(string name,int id);

        Course* addCourse(Course *course);
        bool deleteCourse(Course *course);
        void print_course_ref();

        bool operator==(const Student& other) const;
        bool operator!=(const Student& other) const;

        Course* getCourse(Course* course);

        ~Student();

    private:
        string name;
        int id;
        //course references (this is going to be a dynamic array)
        Course *course_ref;
        int num_of_courses = 0;



};



}

#endif