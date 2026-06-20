#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include "Student.h"

using namespace std;

class StudentList{
    private:
        vector <Student> students;
        string filename = "StudentList.txt";
    public:
        
        StudentList(){
            loadStudentList();
        }
        
        void addStudent(){
            string studentName;
            string studentId;
            
            cout << "Enter Student ID: ";
            getline(cin, studentId);
            
            for (size_t i = 0; i < students.size(); i++){
                if (studentId == students.at(i).getStudentId()){
                    cout << "Student already exist.\n";
                    return;
                }
            }
            
            cout << "Enter Student Name: ";
            getline(cin, studentName);
            Student newStudent(studentName, studentId);
            students.push_back(newStudent);
            cout << "Student successfully added.\n";
        }
        
        void updateStudentGrade(){
                  
            if (checkStudent()){
                cout << "No student listed yet.\n";
                return;
            }
            
            string id, cName;
            cout << "Enter Student ID: ";
            getline(cin, id);
            
            for (size_t i = 0; i < students.size(); i++){
                Student &s = students.at(i);
                vector <string> courses = s.getCourses();
                
                if (id == s.getStudentId()){
                
                    cout << "Enter course name: ";
                    getline(cin, cName);
                
                    int j = 0;
                    double g;
                    for (size_t k = 0; k < courses.size(); k++){
                        if (cName == courses.at(k)){
                            cout << "Grades: ";
                            cin >> g;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                            s.updateGrade(k, g);
                            s.getAverage();
                            return;
                        }
                        j++;
                    }
                }
            }
            cout << "Student not found.\n";
             
        }
        
        void addStudentCourse(CoursesList &cL){
            
            if (checkStudent()){
                cout << "No student listed yet.\n";
                return;
            }
                        
            string id;
            cout << "Enter Student ID: ";
            getline(cin, id);
            
            for (size_t i = 0; i < students.size(); i++){
                Student &s = students.at(i);
                vector <string> courses = s.getCourses();
                
                if (id == s.getStudentId()){
                    vector<Course> courseOptions = cL.getCourses();
                    s.addCourse(courseOptions);
                    return;
                }
            }

            cout << "Student not found.\n";
        }
        
        void saveStudentList(){
            ofstream file(filename.c_str());    
            
            vector <string> coursesTaking;
            vector <double> grades;
            
            if (file.is_open()){
                for (size_t i = 0; i < students.size(); i++){
                    Student &s = students.at(i);
                    coursesTaking = s.getCourses();
                    grades = s.getGrades();
                    
                    file << s.getStudentName() << endl;
                    file << s.getStudentId() << endl;
                    file << s.getNumberOfCoursesTaking() << endl;
                    file << s.getAverage() << endl;
                    
                    for (size_t j = 0; j < coursesTaking.size(); j++)
                        file << coursesTaking.at(j) << endl;
                    for (size_t k = 0; k < grades.size(); k++)
                        file << grades.at(k) << endl;                
                    
                    file << "-------------------------------------------------------------------------------" << endl;
                }
            }
        }
        
        void loadStudentList(){
            string sn, sid, cTs, a, gS, nOCT, line;
            vector <string> cT;
            vector <double> g;
            
            ifstream file(filename.c_str());
            if (!file.is_open()) return;
            
            students.clear();
            if (file.is_open()){
                while (getline(file, sn)){
                    getline(file, sid);
                    getline(file, nOCT);
                    getline(file, a);
                    
                    
                    for(int i = 0; i < maxCourse; i++){
                        getline(file, cTs);
                        cT.push_back(cTs);
                    }
                    for(int i = 0; i < maxCourse; i++){
                        getline(file, gS);
                        g.push_back(stod(gS));
                    }
                    
                    getline(file, line);
                    Student s(sn, sid, stod(a), cT, g, stoi(nOCT));
                    students.push_back(s);
                    cT.clear();
                    g.clear();
                }
            }
        }
        
        bool checkStudent(){
            if (students.empty()) return true;
            return false;
        }
            
                
        void displayOneStudent(){
            if (checkStudent()){
                cout << "No student listed yet.\n";
                return;
            }
            
            vector <string> coursesTaking;
            vector <double> grades;
            string id;
            int numberOfCoursesTaking;
            
            cout << "Enter Student ID: ";
            getline(cin, id);
            
            for (size_t i = 0; i < students.size(); i++){
                Student &s = students.at(i);
                coursesTaking = s.getCourses();
                grades = s.getGrades();
                
                if (s.getStudentId() == id){
                    cout << "---------------\n";
                    cout << "Name: " << s.getStudentName() << endl;
                    cout << "ID: " << s.getStudentId() << endl;
                    cout << "Average: " << s.getAverage() << endl;
                    cout << "Courses taking: ";
                    for (int i = 0; i < s.getNumberOfCoursesTaking(); i++)
                        cout << coursesTaking.at(i) << ": " << grades.at(i) << endl;
                }
            }
        }
        
        void displayStudents(){
            if (checkStudent()){
                cout << "No student listed yet.\n";
                return;
            }
            
            vector <string> coursesTaking;
            vector <double> grades;
            
            for (size_t i = 0; i < students.size(); i++){
                Student &s = students.at(i);
                coursesTaking = s.getCourses();
                grades = s.getGrades();
                cout << "---------------\n";
                cout << "Name: " << s.getStudentName() << endl;
                cout << "ID: " << s.getStudentId() << endl;
                cout << "Average: " << s.getAverage() << endl;
                cout << "Courses taking: " << endl;
                for (int i = 0; i < s.getNumberOfCoursesTaking(); i++)
                    cout << coursesTaking.at(i) << ": " << grades.at(i) << endl;
            }
        }       
};

#endif