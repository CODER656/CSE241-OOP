#include "SchoolManagerSystem.h"


using namespace PA4;


SchoolManagerSystem::SchoolManagerSystem()
{
}


SchoolManagerSystem::SchoolManagerSystem(const SchoolManagerSystem &other)
{
}

SchoolManagerSystem &SchoolManagerSystem::operator=(const SchoolManagerSystem &other)
{
    // TODO: insert return statement here
    return *this;
}




void SchoolManagerSystem::menu()
{

    int main_choice =-1,select_stud_choice=-1;
    int stud_choice=-1,course_choice=-1,select_course_choice=-1;
    string name1,name2;
    int id1,id2;
   
    int code;
    string course_name;

    cout << "Main Menu\n";

    while(main_choice != 0)
    {

        cout<< "0 exit\n";
        cout<< "1 student\n";
        cout<< "2 course\n"; 
        cout<< "3 list_all_students\n";
        cout<< "4 list_all_courses\n";

        
        cin >> main_choice;

        if (main_choice == 1)
        {
            stud_choice=-1;

            while (stud_choice!=0)
            {
                cout<< "0 up\n";
                cout<< "1 add_student\n";
                cout<< "2 select_student\n";

                cin>>stud_choice;

                if (stud_choice == 1)
                {
                    cin>>name1>>id1; //getting the name and id of the new student
                    Student* student = new Student(name1,id1); //creating a new student
                    add_student(student); //adding the student to the array of students
                }
                if (stud_choice == 2)
                {
                    cin >> name2 >> id2; //getting the name and id of the selected student
                    Student* student = new Student(name2,id2); //creating a new student



                    select_stud_choice=-1;
                    while (select_stud_choice!=0)
                    {
                        cout<< "0 up\n";
                        cout<< "1 delete_student\n";
                        cout<< "2 add_selected_student_to_a_course\n";
                        cout<< "3 delete_selected_student_from_a_course\n";

                        cin>>select_stud_choice;

                        if (select_stud_choice == 1)
                        { 
                            delete_student(student); //deleting the student from the array of student
                            select_stud_choice=0;
                        }
                        if(select_stud_choice == 2)
                        { 
                            int choice;
                            cout << "0 up\n";
                            for (int i = 0; i < num_of_courses_sms ; i++) //printing the courses
                                cout << i+1 << " " << course_ref_sms[i].getCode() << " " << course_ref_sms[i].getName() << endl;//printing the courses
                            cin >> choice;

                            if(choice==0)
                                select_course_choice=0;

                            Course* course = new Course(course_ref_sms[choice-1].getCode(),course_ref_sms[choice-1].getName());//creating a new course
                            course->addStudent(student);//adding the student to the course

                            //add_selected_student_to_a_course(student,course);
                        }
                        if(select_stud_choice == 3)
                        {
                            int choice;
                            cout << "0 up\n";
                            for (int i = 0; i < num_of_courses_sms ; i++) //printing the courses
                                cout << i+1 << " " << course_ref_sms[i].getCode() << " " << course_ref_sms[i].getName() << endl;
                            cin >> choice;

                            if(choice==0)
                                select_course_choice=0;
                            
                            Course* course = new Course(course_ref_sms[choice-1].getCode(),course_ref_sms[choice-1].getName());//creating a new course
                            course->deleteStudent(student);
                        }
                    }
                }
            }
            
            
        }
        else if (main_choice == 2)
        {
            cout<<"0 up\n";
            cout<<"1 add_course\n";
            cout<<"2 select_course\n";

            cin>>course_choice;

            if (course_choice == 1)
            {
                int code;string course_name;
                cin>>code>>course_name;
                Course* course = new Course(code,course_name);//creating a new course

                add_course(course);
            }

            if (course_choice == 2)
            {
                cin >> code >> course_name;  //getting the code and name of the selected course
                Course* course = new Course(code,course_name);//creating a new course
                
                for (int i = 0; i < num_of_courses_sms; i++)
                {
                    if (course_ref_sms[i].getCode() == code)///checking if the code is already taken
                    {
                        course = &course_ref_sms[i];//setting the course to the selected course
                        break;
                    }
                   
                    
                }
                
                

                select_course_choice=-1;
                while(select_course_choice!=0)
                {
                    cout<<"0 up\n";
                    cout<<"1 delete_course\n";
                    cout<<"2 list_students_registered_to_the_selected_course\n";


                    cin>>select_course_choice;
                    if (select_course_choice == 1)
                    {
                        delete_course(course);//deleting the course from the array of courses
                        select_course_choice=0;
                    }
                    if (select_course_choice == 2)
                    {
                        course->print_student_ref();
                        //list_students_registered_to_the_selected_course(course);
                    }
                }
            }
        
        }
        else if (main_choice == 3)
        {
            list_all_students();//printing all the students 
        }
        else if (main_choice == 4)
        {
            list_all_courses();//printing all the courses
        }
     
    }
}


void SchoolManagerSystem::add_student(Student *student)
{
    bool found = false;

    for (int i = 0; i < num_of_students_sms; i++)
    {
        if (student_ref_sms[i] == *student)//checking if the student is already in the array
        {
            found = true;//setting found to true
            break;
        }
    }

    if(!found)
    {
        if (num_of_students_sms == 0)//checking if the array is empty
        {
            student_ref_sms = new Student[1];//creating a new array
            student_ref_sms[0] = *student;//adding the student to the array
            num_of_students_sms++;//increasing the number of students
        }
        else
        {
            Student *new_arr = new Student[num_of_students_sms+1];//creating a new array
            for (int i = 0; i < num_of_students_sms; i++)//copying the old array to the new array
            {
                new_arr[i] = student_ref_sms[i];
            }
            new_arr[num_of_students_sms] = *student; //adding student to a course array
            num_of_students_sms++;//increasing the number of students
            delete [] student_ref_sms;//deleting the old array
            student_ref_sms = new_arr;//setting the old array to the new array
        }
    }
    
}


bool SchoolManagerSystem::delete_student(Student *student)
{
    bool found = false;

    for (int i = 0; i < num_of_students_sms; i++)//checking if the student is in the array
    {
        if (student_ref_sms[i] == *student)//checking if the student is in the array
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        if(num_of_students_sms == 0)
            return 0;
        else
        {
            int j=0;
            Student *new_arr = new Student[num_of_students_sms-1];//creating a new array
            for (int i = 0; i < num_of_students_sms; i++)
            {
                if(student_ref_sms[i] != *student)//copying the old array to the new array
                {
                    new_arr[j] = student_ref_sms[i];
                    j++;
                }
            }
            delete[] student_ref_sms;//deleting the old array
            student_ref_sms = new_arr; //setting the old array to the new array
            num_of_students_sms--;   
        }
    }

    return found;

}


//it should add the student student_ref array inside course class
void SchoolManagerSystem::add_selected_student_to_a_course(Student *student,Course *course)
{


    course->addStudent(student);//adding the student to the course


    
    
}


void SchoolManagerSystem::list_students_registered_to_the_selected_course(Course *course)
{
    course->print_student_ref();///printing the students registered to the course
    
       
}

void SchoolManagerSystem::list_students_registered_to_the_selected_course(Student *student)
{
    for (int i = 0; i < num_of_courses_sms; i++)
    {
        if (course_ref_sms[i].getStudent(student) != nullptr)///checking if the student is registered to the course
        {
            cout << course_ref_sms[i].getCode() << " " << course_ref_sms[i].getName() << endl;//printing the course
        }
    }
}

//this will list the courses which are taken by the student
void SchoolManagerSystem::drop_selected_student_from_a_course(Student* student)
{ 
    int choice;

    for (int i = 0; i < num_of_courses_sms; i++)
    {
        if (num_of_courses_sms == 0)
            break;
        if (course_ref_sms[i].getStudent(student) != nullptr)//checking if the student is registered to the course
        {
            cout << "0 up\n";
            cout << i+1 << " " << course_ref_sms[i].getCode() << " " << course_ref_sms[i].getName() << endl;//printing the course
            cin >> choice;

            if(choice == 0)
                break;
            else if (choice == i+1)
            {
                course_ref_sms[i].deleteStudent(student);//deleting the student from the course
            }
        }
        
    }
    
    
    
}


void SchoolManagerSystem::add_course(Course *course)
{
    bool found = false;

    for (int i = 0; i < num_of_courses_sms; i++)
    {
        if (course_ref_sms[i] == *course)//checking if the course is already in the array
        {
            found = true;
            break;
        }
    }
    if(!found)
    {
        if (num_of_courses_sms == 0)
        {
            course_ref_sms = new Course[1];//creating a new array
            course_ref_sms[0] = *course;
            num_of_courses_sms++;
        }
        else
        {
            Course *new_arr = new Course[num_of_courses_sms+1];
            for (int i = 0; i < num_of_courses_sms; i++)
            {
                new_arr[i] = course_ref_sms[i];//copying the old array to the new array
            }
            new_arr[num_of_courses_sms] = *course; //adding student to a course array
            num_of_courses_sms++;
            delete [] course_ref_sms;
            course_ref_sms = new_arr;
        }
    }
}


bool SchoolManagerSystem::delete_course(Course *course)
{
    bool found = false;

    for (int i = 0; i < num_of_courses_sms; i++)
    {
        if (course_ref_sms[i] == *course)//checking if the course is in the array
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        if(num_of_courses_sms == 0)
            return 0;
        else
        {
            int j=0;
            Course *new_arr = new Course[num_of_courses_sms-1];//creating a new array
            for (int i = 0; i < num_of_courses_sms; i++)
            {
                if(course_ref_sms[i] != *course)//copying the old array to the new array
                {
                    new_arr[j] = course_ref_sms[i];
                    j++;
                }
            }
            delete[] course_ref_sms;
            course_ref_sms = new_arr;         
            num_of_courses_sms--;   
        }
    }

    return found;
}




//cout << course.getStudentRef()[i].getName() << " " << course.getStudentRef()[i].getId() << endl; 


void SchoolManagerSystem::list_all_students()
{
    for (int i = 0; i < num_of_students_sms; i++)
    {
        cout<<student_ref_sms[i].getName()<<" "<<student_ref_sms[i].getId()<<endl;//printing the student
    }
}


void SchoolManagerSystem::list_all_courses()
{
    for (int i = 0; i < num_of_courses_sms; i++)
    {
        cout << course_ref_sms[i].getCode() << " " << course_ref_sms[i].getName() << endl;//printing the course
    }
    
}

void SchoolManagerSystem::set_course_ref(Course *course)
{
    this->course_ref_sms = course;//setting the course_ref_sms to the course
}

void SchoolManagerSystem::set_student_ref(Student *student)
{
    this->student_ref_sms = student;//setting the student_ref_sms to the student
}

SchoolManagerSystem::~SchoolManagerSystem()
{
    delete [] student_ref_sms;//deleting the student_ref_sms
    delete [] course_ref_sms;// deleting the course_ref_sms
    student_ref_sms = nullptr;//setting the student_ref_sms to nullptr
    course_ref_sms = nullptr;
}

