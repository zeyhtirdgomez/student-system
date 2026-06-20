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
class Student
{
private:
    string studentName;
    string studentId;
    double average;
    vector<string> coursesTaking;
    vector<double> grades;
    int numberOfCoursesTaking;

public:
    Student(string sn, string sid) : studentName(sn), studentId(sid),
                                     numberOfCoursesTaking(0), average(0)
    {
        coursesTaking.assign(maxCourse, "Empty");
        grades.assign(maxCourse, 0.0);
    }

    Student(string sn, string sid, double a, vector<string> cT, vector<double> g, int nOCT) : 
    studentName(sn), studentId(sid), average(a), coursesTaking(cT), grades(g), numberOfCoursesTaking(nOCT) {}

    void addCourse(vector<Course> &cL)
    {

        if (numberOfCoursesTaking >= maxCourse)
        {
            cout << "Course limit reached.\n";
            return;
        }

        string courseName;
        cout << "Course name: ";
        getline(cin, courseName);

        cout << "Courses currently taking: "<< numberOfCoursesTaking <<endl;
        
        for (size_t i = 0; i < numberOfCoursesTaking; ++i)
        {
            cout << coursesTaking.at(i) << endl;
            if (courseName == coursesTaking.at(i))
            {
                cout << "You are already enrolled in this course.\n";
                return;
            }
        } // Check if the student is already enrolled in the course

        for (size_t i = 0; i < cL.size(); ++i)
        {
            if (courseName == cL.at(i).getCourseName())
            {
                coursesTaking.at(numberOfCoursesTaking) = cL.at(i).getCourseName();
                cout << "Course successfully listed.\n";
                numberOfCoursesTaking++;
                return;
            }
        }

        cout << "Course not found.\n";
    }

    void updateGrade(int index, double g)
    {
        grades.at(index) = g;
    }

    void calculateStudentAverage()
    {
        double sum = 0;
        for (size_t i = 0; i < grades.size(); ++i)
            sum += grades.at(i);
        average = sum / numberOfCoursesTaking;
    }

    double getAverage()
    {
        if (numberOfCoursesTaking == 0)
            return 0;
        calculateStudentAverage();
        return average;
    }

    string getStudentId()
    {
        return studentId;
    }

    string getStudentName()
    {
        return studentName;
    }

    int getNumberOfCoursesTaking()
    {
        return numberOfCoursesTaking;
    }

    vector<string> getCourses()
    {
        return coursesTaking;
    }

    vector<double> getGrades()
    {
        return grades;
    }
};

#endif