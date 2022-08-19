#ifndef INTERIMREPORT_STUDENT_HPP
#define INTERIMREPORT_STUDENT_HPP

#include <iostream>
#include <vector>
using namespace std;
class Student
{
protected:
    string firstName;
    string lastName;
    float cgpa;
    int researchScore;
    int applicationId;
    int strikes;
    Student* next;
public:
    static const int STUDENT = 0;
    static const int DOMESTIC_STUDENT = 1;
    static const int INTERNATIONAL_STUDENT = 2;

    Student();
    Student(const Student &student);
    Student(const string &firstNameIn, const string &lastNameIn, const float &cgpaIn, const int &researchScoreIn, const int &applicationIdIn);

    int getType() const;
    string getFirstName() const;
    string getLastName() const;
    float get_cgpa() const;
    int getResearchScore() const;
    int getApplicationId() const;

    void setFirstName(const string &firstNameIn);
    void setLastName(const string &lastNameIn);
    void set_cgpa(const float &cgpaIn);
    void setResearchScore(const int &researchScoreIn);
    //void setApplicationId(const int &applicationIdIn);

    string toString() const;

    friend ostream &operator<<(ostream &os, const Student &student);

    bool operator==(const Student &rhs) const;

    friend int compareResearchScore(const Student& stu1, const Student& stu2);
    friend int compareCGPA(const Student& stu1, const Student& stu2);
    friend int compareFirstName(const Student& stu1, const Student& stu2);
    friend int compareLastName(const Student& stu1, const Student& stu2);

    static vector<Student*> searchA(int id, Student* head);   //to look for students with specified application id
    static vector<Student*> searchR(int score, Student* head); //to look for students with specified research score
    static vector<Student*> searchC(float cgpa, Student* head); //to look for students with specified gpa
    static vector<Student*> searchName(const string &firstName,const string &lastName, Student* &head); //to look for students with specified name


    // returns next pointer of student
    bool insertMerged( Student** head );

    Student* getNext();
    void setNext( Student* a_next );

    void incrementStrike();
    int getStrike();
};

typedef Student* StudentPtr;

bool checkString( string name );
//serchname helper func
string toLowerString(string name);//recursive func to lowercase string

bool trimHeadTail( StudentPtr* head );

void addStrike( Student* head );
void disciplinaryInquiry( Student* head );

#endif //INTERIMREPORT_STUDENT_HPP
