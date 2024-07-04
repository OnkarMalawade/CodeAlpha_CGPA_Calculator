#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Course {
public:
    string name;
    int credits;
    float grade;

    Course(const string& name, int credits, float grade) : name(name), credits(credits), grade(grade) {}
};

class CGPACalculator {
private:
    vector<Course> courses;
    float totalCredits;
    float totalGradePoints;

public:
    CGPACalculator() : totalCredits(0.0), totalGradePoints(0.0) {}

    void inputCourseDetails() {
        int numberOfCourses;
        cout << "Enter the number of courses taken: ";
        cin >> numberOfCourses;

        for (int i = 0; i < numberOfCourses; ++i) {
            string name;
            int credits;
            float grade;

            cout << "Enter details for course " << i + 1 << endl;
            cout << "Course name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Credits: ";
            cin >> credits;
            cout << "Grade (in GPA format, e.g., 4.0): ";
            cin >> grade;

            courses.push_back(Course(name, credits, grade));
        }
    }

    void calculateGPA(float& GPA) {
        for (size_t i = 0; i < courses.size(); ++i) {
            totalCredits += courses[i].credits;
            totalGradePoints += courses[i].grade * courses[i].credits;
        }
        GPA = totalGradePoints / totalCredits;
    }

    void calculateCGPA(float& CGPA) {
        CGPA = totalGradePoints / totalCredits;
    }

    void displayCourseDetails() const {
        cout << "Course Details:" << endl;
        for (size_t i = 0; i < courses.size(); ++i) {
            cout << "Course Name: " << courses[i].name << ", Credits: " << courses[i].credits << ", Grade: " << courses[i].grade << endl;
        }
    }

    float getTotalCredits() const {
        return totalCredits;
    }

    float getTotalGradePoints() const {
        return totalGradePoints;
    }
};

int main() {
    CGPACalculator calculator;
    float GPA = 0.0, CGPA = 0.0;

    cout << "Welcome to the CGPA Calculator" << endl;

    // Input course details
    calculator.inputCourseDetails();

    // Calculate GPA for the semester
    calculator.calculateGPA(GPA);

    // Calculate CGPA
    calculator.calculateCGPA(CGPA);

    // Display course details and results
    calculator.displayCourseDetails();
    cout << "Total Credits: " << calculator.getTotalCredits() << endl;
    cout << "Total Grade Points: " << calculator.getTotalGradePoints() << endl;
    cout << "GPA for the semester: " << fixed << setprecision(2) << GPA << endl;
    cout << "Cumulative Grade Point Average (CGPA): " << fixed << setprecision(2) << CGPA << endl;

    return 0;
}

