#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Student class to encapsulate student-related operations
class Student {
public:
    string name;
    int id, batch;
    long long contact;
    float pfMarks, calculusMarks, physicsMarks;

    // Function to calculate and display grades
    void calculateGrade() const {
        displayGrade("Programming Fundamentals", pfMarks);
        displayGrade("Calculus", calculusMarks);
        displayGrade("Physics", physicsMarks);
    }

private:
    static void displayGrade(const string& subject, float marks) {
        cout << "\tGrade for " << subject << ": ";
        if (marks >= 90.0) cout << "A+" << endl;
        else if (marks >= 86.0) cout << "A" << endl;
        else if (marks >= 82.0) cout << "A-" << endl;
        else if (marks >= 78.0) cout << "B+" << endl;
        else if (marks >= 74.0) cout << "B" << endl;
        else if (marks >= 70.0) cout << "B-" << endl;
        else if (marks >= 66.0) cout << "C+" << endl;
        else if (marks >= 62.0) cout << "C" << endl;
        else if (marks >= 58.0) cout << "C-" << endl;
        else if (marks >= 54.0) cout << "D+" << endl;
        else if (marks >= 50.0) cout << "D" << endl;
        else cout << "F" << endl;
    }
};

// System class to handle operations
class StudentSystem {
public:
    void run() {
        int choice;
        do {
            displayMenu();
            if (!getValidInput(choice)) {
                cout << "Invalid input. Please enter a number between 1 and 5.\n";
                continue;
            }

            switch (choice) {
                case 1: addStudent(); break;
                case 2: viewStudentRecords(); break;
                case 3: searchStudent(); break;
                case 4: deleteStudent(); break;
                case 5: cout << "Exiting the program...\n"; break;
                default: cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }

private:
    vector<Student> students; // Vector to store student records

    void displayMenu() const {
        cout << "\n************* Student Information System **************\n";
        cout << "1. Add Student Information\n";
        cout << "2. View Student Information\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student Information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }

    bool getValidInput(int& input) {
        cin >> input;
        if (cin.fail() || input < 1 || input > 5) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            return false;
        }
        return true;
    }

    bool getValidInput(float& input) {
        cin >> input;
        if (cin.fail() || input < 0.0 || input > 100.0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            return false;
        }
        return true;
    }

    void addStudent() {
        char choice;
        do {
            Student s;
            cout << "Enter Student Name: ";
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, s.name);

            cout << "Enter Batch: ";
            while (!getValidInput(s.batch)) {
                cout << "Invalid input. Enter a valid batch: ";
            }

            cout << "Enter ID: ";
            while (!getValidInput(s.id)) {
                cout << "Invalid input. Enter a valid ID: ";
            }

            cout << "Enter Contact Number: ";
            while (!(cin >> s.contact)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a valid contact number: ";
            }

            cout << "Enter marks for Programming Fundamentals: ";
            while (!getValidInput(s.pfMarks)) {
                cout << "Invalid input. Enter valid marks (0-100): ";
            }

            cout << "Enter marks for Calculus: ";
            while (!getValidInput(s.calculusMarks)) {
                cout << "Invalid input. Enter valid marks (0-100): ";
            }

            cout << "Enter marks for Physics: ";
            while (!getValidInput(s.physicsMarks)) {
                cout << "Invalid input. Enter valid marks (0-100): ";
            }

            students.push_back(s); // Add student to vector
            cout << "Student record added successfully.\n";
            cout << "Do you want to add another student? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    void viewStudentRecords() const {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\n************* Students Record **************\n";
        for (const auto& s : students) {
            displayStudent(s);
        }
    }

    void searchStudent() const {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        int searchID;
        cout << "Enter Student ID to search: ";
        while (!getValidInput(searchID)) {
            cout << "Invalid input. Enter a valid ID: ";
        }

        bool found = false;
        for (const auto& s : students) {
            if (s.id == searchID) {
                displayStudent(s);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found.\n";
        }
    }

    void deleteStudent() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        int deleteID;
        cout << "Enter Student ID to delete: ";
        while (!getValidInput(deleteID)) {
            cout << "Invalid input. Enter a valid ID: ";
        }

        auto it = remove_if(students.begin(), students.end(), [deleteID](const Student& s) {
            return s.id == deleteID;
        });

        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student record deleted successfully.\n";
        } else {
            cout << "Student not found.\n";
        }
    }

    static void displayStudent(const Student& s) {
        cout << "\nStudent Name: " << s.name
             << "\nBatch: " << s.batch
             << "\nID: " << s.id
             << "\nContact: " << s.contact
             << "\nProgramming Fundamentals Marks: " << s.pfMarks
             << "\nCalculus Marks: " << s.calculusMarks
             << "\nPhysics Marks: " << s.physicsMarks << endl;
        s.calculateGrade();
    }
};

int main() {
    StudentSystem system;
    system.run();
    return 0;
}
