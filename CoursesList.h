#ifndef COURSESLIST_H
#define COURSESLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include "Course.h"
using namespace std;

//CoursesList class
class CoursesList{
    private:
        //Attributes
        vector <Course> courses;
        int maxCourse;
        string filename = "courselist.txt";

    public:
        //Constructor
        CoursesList(): maxCourse(10){
            loadCourseList();
        }
        
        //Check if course list is empty
        bool emptyCourseList(){
            if (courses.empty()) return true;
            return false;
        }
        
        //Add a course to the list
        void addCourse(){
            if (courses.size() >= maxCourse){
                cout << "Limit reached.\n";
                return;
            } // Check if the maximum number of courses has been reached
            
            string name, faculty;
            double units;
            
            
            cout << "Course name: ";
            getline(cin, name);
            
            for (size_t i = 0; i < courses.size(); i++){
                if (name == courses[i].getCourseName()){
                    cout << "Course already exist.\n";
                    return;
                }
            } // Check if the course already exists in the list
            
            cout << "Faculty name: ";
            getline(cin, faculty);
            
            cout << "How many units: ";
            cin >> units;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            Course c(name, faculty, units);
            courses.push_back(c);
            
            saveCourseList();
        }
        
        //Remove a course from the list
        void removeCourse(){
            
            if (emptyCourseList()){
                cout << "Course list is empty.\n";
                return;
            }
            
            string name;
            bool isFound = false;
            cout << "Course name: ";
            getline(cin, name);
            
            for(int i = 0; i < courses.size(); i++){
                if (courses[i].getCourseName() == name){
                    courses.erase(courses.begin()+i);
                    isFound = true;
                }
            } // Check if the course exists in the list and remove it
            
            if (!isFound) cout << "Invalid course name.\n";
        }
        
        vector <Course> getCourses(){
            return courses;
        } // Get the list of courses
        
        void displayCourses(){
            
            if (emptyCourseList()){
                cout << "Course list is empty.\n";
                return;
            }
            
            for (size_t i = 0; i < courses.size(); i++)
                courses[i].display();
        } // Display the list of courses
        
        void saveCourseList(){
            ofstream file(filename.c_str());
            if(file.is_open()){
                for (size_t i = 0; i < courses.size(); i++){
                    file << courses[i].getCourseName() << endl;
                    file << courses[i].getFaculty() << endl;
                    file << courses[i].getUnits() << endl;
                    file << "-------------------------------------------------------------------------------" << endl;
                }
            }
            
            file.close();
        } // Save the list of courses to a file
        
        void loadCourseList(){
            ifstream file(filename.c_str());
            string name, faculty, units, line;
            
            if (!file.is_open()) return;
            courses.clear();
            
            while(getline(file, name)){
                getline(file, faculty);
                getline(file, units);
                getline(file, line);
                double unitsValue = 0;
                stringstream ss(units);
                ss >> unitsValue;
                Course c(name, faculty, unitsValue); // Create a Course object using the data read from the file
                courses.push_back(c);
            }
            
            file.close();
        } // Load the list of courses from a file
};

#endif