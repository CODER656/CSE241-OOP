#include "util.h"

using namespace FurkanT;


void call_val_test(DayofYearSet test,DayofYearSet::DayofYear d1){
    
    cout << "Removing element from set" <<  endl;
    test.remove(d1);
    cout << "After removed:"  << test << endl;

}

void call_ref_test(DayofYearSet& test, DayofYearSet::DayofYear &d1){

    cout << "Removing element from set" <<  endl;
    test.remove(d1);
    cout << "After removed:"  << test << endl;

}



int main() {

    DayofYearSet::DayofYear day1(4,4);
    DayofYearSet::DayofYear day2(22,8);
    DayofYearSet::DayofYear day3(17,5);

    DayofYearSet::DayofYear day4(23,6);
    DayofYearSet::DayofYear day5(27,2);
    DayofYearSet::DayofYear day6(12,12);

    DayofYearSet::DayofYear day7(14,5);
    DayofYearSet::DayofYear day8(11,10);
    DayofYearSet::DayofYear day9(25,6);

    DayofYearSet::DayofYear day10(21,2);
    DayofYearSet::DayofYear day11(1,10);
    DayofYearSet::DayofYear day12(16,12);

    cout <<"===================================================";
    cout << "\nDayofYear Default Constructer Test1:\n";
    DayofYearSet::DayofYear default_cons1;
    cout << "Day/Month:" << default_cons1 << endl;
    cout << endl << "Day:" << default_cons1.get_day() << endl <<  "Month:" << default_cons1.get_month() << endl;
    cout <<"===================================================";

    cout << "\nDayofYear Default Constructer Test2:\n";
    DayofYearSet::DayofYear default_cons2;
    cout << "Day/Month:" << default_cons2 << endl;
    cout << endl << "Day:" << default_cons2.get_day() << endl <<  "Month:" << default_cons2.get_month() << endl;
    cout <<"===================================================";


    cout << "\nDayofYear Constructer with parameter Test1:\n";
    DayofYearSet::DayofYear param_cons1(13,4);
    cout << "Day/Month:" << param_cons1 << endl;
    cout << endl << "Day:" << param_cons1.get_day() << endl <<  "Month:" << param_cons1.get_month() << endl;
    cout <<"===================================================";

    cout << "\nDayofYear Constructer with parameter Test2:\n";
    DayofYearSet::DayofYear param_cons2(21,7);
    cout << "Day/Month:" << param_cons2 << endl;
    cout << endl << "Day:" << param_cons2.get_day() << endl <<  "Month:" << param_cons2.get_month() << endl;
    cout <<"===================================================";

    cout << "\nDayofYear Copy Constructer Test1:\n";
    DayofYearSet::DayofYear copy_cons1(param_cons1);
    cout << "Day/Month:" << copy_cons1 << endl;
    cout << endl << "Day:" << copy_cons1.get_day() << endl <<  "Month:" << copy_cons1.get_month() << endl;
    cout <<"===================================================";

    cout << "\nDayofYear Copy Constructer Test2:\n";
    DayofYearSet::DayofYear copy_cons2(param_cons2);
    cout << "Day/Month:" << copy_cons2 << endl;
    cout << endl << "Day:" << copy_cons2.get_day() << endl <<  "Month:" << copy_cons2.get_month() << endl;
    cout <<"===================================================";


    cout <<"===================================================";
    cout << "\nDayofYearSet TESTS:\n";
    cout <<"===================================================";
 

    cout << "\nDayofYearSet Default Constructer Test:\n";
    DayofYearSet doys_def_cons;
    cout << "DayofYearSet Default Constructer:" << doys_def_cons << endl;
    cout <<"===================================================";


    DayofYearSet doys1 = {day1, day2, day3};

    cout << "\nDayofYearSet List Initializer Constructer" << endl;
    cout << "and operator<< test:\n\n";
   
    cout << "doys1:" << doys1 << endl;

    
    DayofYearSet doys2 = {day4, day5, day6};

    cout << "doys2:" << doys2 << endl;

    DayofYearSet doys3 = {day7, day8, day9};

    cout << "doys3:" << doys3 << endl;

    
    doys1.seperator();
    DayofYearSet doys4 = doys1 + doys2;
    cout << "\nDayofYearSet operator+ returns the union set test:\n" << endl;
    cout << "doys1+doys2 =" << doys4 << endl;

    DayofYearSet doys5 = doys2 + doys3;
    cout << "doys2+doys3 =" << doys5 << endl;




    doys1.seperator();
    cout << "\nDayofYearSet operator+ adds an element to set test:\n" << endl;
    cout << "doys1 ="<< doys1 << endl;
    cout << "day7 =" << day7 << endl;
    doys1 + day7;
    cout << "doys1 + day7 =" << doys1 << endl;

    
    DayofYearSet doys22 = {day10, day11, day12};
    cout << "\ndoys22 =" << doys22 << endl;
    cout << "day5 =" << day5 << endl;
    doys22 + day5;
    cout << "doys22 + day5 =" << doys22 << endl;







    doys1.seperator();
    cout << "\nDayofYearSet operator== test:\n" << endl;
    cout << "doys1 =" << doys1 << endl;
    cout << "doys2 =" << doys2 << endl;
    DayofYearSet doys6 = {day1, day2, day3};
    cout << "doys6 =" << doys6 << endl;

    DayofYearSet doys7 = {day4, day5, day6};
    cout << "doys7 =" << doys7 << endl;

    if (doys1 == doys6)
        cout << "doys1 and doys6 are equal" << endl;
    else
        cout << "doys1 and doys6 are not equal" << endl;
    
    if (doys2 == doys7)
        cout << "doys2 and doys7 are equal" << endl;
    else
        cout << "doys2 and doys7 are not equal" << endl;


    doys1.seperator();
    cout << "\nDayofYearSet operator!= test:\n" << endl;
    if (doys2 != doys6)
        cout << "doys2 and doys6 are not equal" << endl;
    else
        cout << "doys2 and doys6 are equal" << endl;

    if (doys1 != doys7)
        cout << "doys1 and doys7 are not equal" << endl;
    else
        cout << "doys1 and doys7 are equal" << endl;


    doys1.seperator();
    cout << "\nDayofYearSet operator- returns the difference set test:\n";
    DayofYearSet doys8 = {day7,day8,day9};
    cout << "\ndoys8 =" << doys8 << endl;
    DayofYearSet doys9 = {day10,day8,day12};
    cout << "doys9 =" << doys9 << endl;
    DayofYearSet doys10 = doys8 - doys9;
    cout << "doys8 - doys9 =" << doys10 << endl;
    DayofYearSet doys11 = doys9 - doys8;
    cout << "doys9 - doys8 =" << doys11 << endl;

   
    doys1.seperator();
    cout << "\nDayofYearSet operator- removes an element from set test:\n";
    cout << "\ndoys9 =" << doys9 << endl;
    cout << "day8 =" << day8 << endl;
    doys9 - day8;
    cout << "doys9 - day8 =" << doys9 << endl;

    DayofYearSet doys14 = {day1,day2,day3};
    cout << "\ndoys14 =" << doys14 << endl;
    cout << "day1 =" << day1 << endl;
    doys14 - day1;
    cout << "doys14 - day1 =" << doys14 << endl;

    



    doys1.seperator();
    cout << "\nDayofYearSet operator[] test:\n";
    cout << "\ndoys1 =" << doys1 << endl;
    cout << "doys1[0] =" << doys1[0] << endl;
    cout << "doys1[1] =" << doys1[1] << endl;
    cout << "doys1[2] =" << doys1[2] << endl;
    cout << "\ndoys2 =" << doys2 << endl;
    cout << "doys2[0] =" << doys2[0] << endl;
    cout << "doys2[1] =" << doys2[1] << endl;
    cout << "doys2[2] =" << doys2[2] << endl;


    doys1.seperator();
    cout << "\nDayofYearSet operator! returns the complement set test:\n";
    DayofYearSet doys12 = {day10,day11,day12};
    cout << "\ndoys12 =" << doys12 << endl;
    DayofYearSet doys13 = !doys12;
    cout << "Complement of doys12 =\n" << doys13 << endl;


    
    doys1.seperator();
    cout << "\nSize Function Test:\n";
    DayofYearSet doys20 = {day1,day2,day1,day2,day1,day2,day1,day2};
    cout << "\ndoys20 =" << doys20 << endl;
    cout << "doys1 =" << doys1 << endl;
    cout << "doys2 =" << doys2 << endl;
    cout << "doys1 size: " << doys1.size() << endl;
    cout << "doys2 size: " << doys2.size() << endl;
     cout << "doys20 size: " << doys20.size() << endl;


    doys1.seperator();
    cout << "\nRemove Function Test:\n";
    cout << "\ndoys1 =" << doys1 << endl;
    doys1.remove(day1);
    cout << "doys1 after removed first one:" << doys1 << endl;
    cout << "\ndoys2 =" << doys2 << endl;
    doys2.remove(day5);
    cout << "doys2 after removed second one:" << doys2 << endl;
    doys1.seperator();


    cout << "Call by Value Test\n";

    DayofYearSet call_test = {day10,day11,day12};

    cout << "Before ="  << call_test << endl;
    call_val_test(call_test,day10);
    doys1.seperator();


    cout << "\nCall by Reference Test\n";


    DayofYearSet ref_test = {day10,day11,day12};

    cout << "Before =" << ref_test << endl;
    call_ref_test(ref_test,day11);
    doys1.seperator();
    


    return 0;
}





