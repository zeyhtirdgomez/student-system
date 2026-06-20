#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include "CoursesList.h"
#include "StudentList.h"
using namespace std;

class Dashboard{
    private:
        CoursesList cList;
        StudentList sList;
    public:
    
        Dashboard(){
            cList.loadCourseList();
            sList.loadStudentList();
        }
        
        void save(){
            cList.saveCourseList();
            sList.saveStudentList();
        }
        
        void menu(){
            string option;
            do{
                cout << "---- Main Menu ----\n";
                cout << "1. Add course\n";
                cout << "2. View courses\n";
                cout << "3. Add student\n";
                cout << "4. Add student's course\n";
                cout << "5. Update student grade\n";
                cout << "6. View student\n";
                cout << "7. Display student\n";
                cout << "8. Exit\n";
                cout << "Choose: ";
                cin >> option;
                
                if (option == "1"){
                    cList.addCourse();
                    save();
                }
                
                else if (option == "2") {
                    cList.displayCourses();
                    save();
                }
                
                else if (option == "3") {
                    sList.addStudent();
                    save();
                }
                
                else if (option == "4"){
                    sList.addStudentCourse();
                    save();
                }
                
                else if (option == "5") {
                    sList.updateStudentGrade();
                    save();
                }
                
                else if (option == "6") {
                    sList.displayOneStudent();
                    save();
                }
                
                else if (option == "7") {
                    sList.displayStudents();
                    save();
                }
                
                else if (option == "8") break;
                else cout << "Invalid input.\n";
            }while(option != "8");
            save();
        }    
    
};


#endif