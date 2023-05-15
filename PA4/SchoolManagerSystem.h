#ifndef SCHOOLMANAGER_H 
#define MYHEASCHOOLMANAGER_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

namespace PA4{


class SchoolManagerSystem{

    public:
        SchoolManagerSystem();
        SchoolManagerSystem(const SchoolManagerSystem &other); 
        SchoolManagerSystem& operator=(const SchoolManagerSystem &other);
        
        void menu();

        void add_student(Student *student);
        bool delete_student(Student *student);
        void add_selected_student_to_a_course(Student *student, Course *course);
        void drop_selected_student_from_a_course(Student *student);
        void add_course(Course *course);
        bool delete_course(Course *course);
        void list_students_registered_to_the_selected_course(Course *course);
        void list_students_registered_to_the_selected_course(Student *student);
        void list_all_students();
        void list_all_courses();


        void set_course_ref(Course *course);
        void set_student_ref(Student *student);
        

        ~SchoolManagerSystem();

    private:
        Course *course_ref_sms;
        Student *student_ref_sms;
        int num_of_courses_sms=0;
        int num_of_students_sms=0;



};






}

#endif