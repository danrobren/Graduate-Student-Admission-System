#ifndef FINALREPORT_INTERNATIONALSTUDENT_HPP
#define FINALREPORT_INTERNATIONALSTUDENT_HPP

#include <ostream>
#include "Student.hpp"
#include "ToeflScore.hpp"
#include "error.hpp"

class InternationalStudent: public Student
{
private:
    string country;
    ToeflScore languageScore;
    InternationalStudent* next = nullptr;

    // PRE: caller node is a valid international student with appropriate parameters (see throw list)
    // POST: caller node is inserted into the list headed by 'head' (caller may become head)
    //		 returns true on successful insert, false if and only if head is a null pointer
    //		 preserves sorting integrity
    // THROW LIST: d_bagCGPA - caller object's cgpa field not within [4.33, 0.00]
    //			   d_badCountry - caller object's province field is not one of China, India, Iran, Korea
    //					note: 'Idian' typo is fixed
    //			   d_badResearch - research score is not within [100, 0]
    //			   e_nullStudent - caller object is null
    //			   d_duplicateNode - node with this memory address already exists in the list
    bool insertInternational( InternationalStudent* &head ) throw( i_error );

public:
    InternationalStudent();
    InternationalStudent(const InternationalStudent &student);
    InternationalStudent(const Student &student, const string &countryIn, const ToeflScore &lang);
    InternationalStudent(const string &firstNameIn, const string &lastNameIn, const float &cgpaIn, const int &researchScoreIn, const int &applicationIdIn, const string &countryIn, const ToeflScore &lang);

    int getType() const;
    string getCountry() const;
    ToeflScore getLanguageScore() const;
    InternationalStudent* getNext() const;

    void setCountry(const string &countryIn);
    void setLanguageScore(const ToeflScore &lang);

    string toString() const;

    friend ostream &operator<<(ostream &os, const InternationalStudent &student);
    bool operator==(const InternationalStudent &student) const;
    bool operator!=(const InternationalStudent &student) const;

    friend int compareCountry(const InternationalStudent& stu1, const InternationalStudent& stu2);
    friend int compareLangScore(const InternationalStudent& stu1, const InternationalStudent& stu2);


    bool insert( InternationalStudent* &head );

    // PRE: head is non-null pointer
    // POST: returns true if a node with caller object's memory address is in the list
    //		returns false on null head or node not in list
    bool searchInternational( InternationalStudent* head );

    // PRE: head is a non-null pointer
    // POST: retruns true if caller object node was deleted from list
    //		returns false if node was not found or null head
    bool deleteInternational( InternationalStudent* &head);


    static vector<InternationalStudent*> searchA(int id, InternationalStudent* head);   //to look for students with specified application id
    static vector<InternationalStudent*> searchR(int score, InternationalStudent* head); //to look for students with specified research score
    static vector<InternationalStudent*> searchC(float cgpa, InternationalStudent* head); //to look for students with specified gpa
    static vector<InternationalStudent*> searchName(const string &firstName,const string &lastName, InternationalStudent* &head); //to look for students with specified name

    void i_setNext( InternationalStudent* a_next );
    InternationalStudent* i_getNext();
};

typedef InternationalStudent* InternationalPtr;

void i_printList( InternationalPtr head );

InternationalPtr i_findTail( InternationalPtr head );

bool i_trimHeadTail( InternationalPtr* head );

#endif //FINALREPORT_INTERNATIONALSTUDENT_HPP
