#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;

const int maxCourse = 8; 
class Student{
    private:
        string studentName;
        string studentId;
        double average;
        vector <string> coursesTaking;
        vector <double> grades;
        int numberOfCoursesTaking;
    
    public:
        Student(string sn, string sid): studentName(sn), studentId(sid),
        numberOfCoursesTaking(0), average(0){
            coursesTaking.assign(maxCourse, "Empty");
            grades.assign(maxCourse, 0.0);
        }
        
        Student(string sn, string sid, double a, vector <string> cT, vector <double> g, int nOCT):
        studentName(sn), studentId(sid), average(a), coursesTaking(cT), grades(g), numberOfCoursesTaking(nOCT){}
        
        void addCourse(){
            
            if (numberOfCoursesTaking >= maxCourse){
                cout << "Course limit reached.\n";
                return;
            }
            
            CoursesList cL;
            vector <Course> cs = cL.getCourses();
            
            string courseName;
            cout << "Course name: ";
            getline(cin, courseName);
            
            for (size_t i = 0; i < cs.size(); ++i){
                if (courseName == cs.at(i).getCourseName()){
                    coursesTaking.at(numberOfCoursesTaking) = cs.at(i).getCourseName();
                    cout << "Course successfully listed.\n";
                    numberOfCoursesTaking++;
                    return;
                }
            }
            
            cout << "Course not found.\n";
        }
        
        void updateGrade(int index, double g){
            grades.at(index) = g;
        }
        
        void calculateStudentAverage(){
            double sum = 0;
            for (size_t i = 0; i < grades.size(); ++i)
                sum += grades.at(i);
            average = sum / numberOfCoursesTaking;
        }
        
        double getAverage(){
            if (numberOfCoursesTaking == 0) return 0;
            calculateStudentAverage();
            return average;
        }
        
        string getStudentId(){
            return studentId;
        }
        
        string getStudentName(){
            return studentName;
        }
        
        int getNumberOfCoursesTaking(){
            return numberOfCoursesTaking;
        }
        
        vector <string> getCourses(){
            return coursesTaking;    
        }
        
        vector <double> getGrades(){
            return grades;
        }
};

#endif