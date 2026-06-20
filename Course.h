#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;
//Course class
class Course{
    private:
        //Attributes
        string courseName;
        string faculty;
        double units;
        
    public:
        //Constructor
        Course(string n, string f, double u): courseName(n), faculty(f), units(u){}
        
        //Display function
        void display(){
            cout << "---------------\n";
            cout << "Course name: " << courseName << endl;
            cout << "Faculty name: " << faculty << endl;
            cout << "Units: " << units << endl;
        }
        
        //Getters and Setters
        void setCourseName(string n) {
                courseName = n;
        } // Set the course name
        
        void setFaculty(string f) {
                faculty = f;
        } // Set the faculty name
        
        void setUnits(double u){
            units = u;
        } // Set the units
        
        string getCourseName(){
            return courseName;
        } // Get the course name
        
        string getFaculty(){
            return faculty;
        } // Get the faculty name
        
        double getUnits(){
            return units;
        } // Get the units
};

#endif