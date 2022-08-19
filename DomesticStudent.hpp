#ifndef FINALREPORT_DOMESTICSTUDENT_HPP
#define FINALREPORT_DOMESTICSTUDENT_HPP


#include <ostream>
#include <vector>
#include "Student.hpp"
#include "error.hpp"

class DomesticStudent :public Student
{

private:
    string province;

    DomesticStudent* next = NULL;

    // PRE: caller node is a valid domestic student with appropriate parameters (see throw list)
    // POST: caller node is inserted into the list headed by 'head' (caller may become head)
    //           returns true on successful insert, false if and only if head is a null pointer
    //           preserves sorting integrity
    // THROW LIST: d_bagCGPA - caller object's cgpa field not within [4.33, 0.00]
    //                     d_badProvince - caller object's province field is not one of NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU
    //                     d_badResearch - research score is not within [100, 0]
    //                     e_nullStudent - caller object is null
    //                     d_duplicateNode - node with this memory address already exists in the list
    bool insertDomestic(DomesticStudent* &head) throw (d_error);

public:
    DomesticStudent();

    DomesticStudent(const DomesticStudent& student);

    DomesticStudent(const Student& student, const string& provinceIn);

    DomesticStudent(const string& firstNameIn, const string& lastNameIn,
                    const float& cgpaIn, const int& researchScoreIn,
                    const int& applicationIdIn, const string& provinceIn);


    int getType() const;

    string getProvince()const;

    void setProvince(const string& provinceIn);

    DomesticStudent* getNext()const;


    string toString()const;


    friend ostream& operator<< (ostream& os,
                                const DomesticStudent& student);


    bool operator== (const DomesticStudent& rhs) const;

    bool operator!= (const DomesticStudent& rhs) const;


    friend int compareProvince(const DomesticStudent& stu1,
                               const DomesticStudent& stu2);


    bool insert(DomesticStudent* &head);



    // PRE: head is non-null pointer
    // POST: returns true if a node with caller object's memory address is in the list
    //          returns false on null head or node not in list
    bool searchDomestic(DomesticStudent* head);


    // PRE: head is a non-null pointer
    // POST: retruns true if caller object node was deleted from list
    //          returns false if node was not found or null head
    bool deleteDomestic(DomesticStudent* &head);


    static vector<DomesticStudent*> searchA(int id, DomesticStudent* head);   //to look for students with specified application id
    static vector<DomesticStudent*> searchR(int score, DomesticStudent* head); //to look for students with specified research score
    static vector<DomesticStudent*> searchC(float cgpa, DomesticStudent* head); //to look for students with specified gpa
    static vector<DomesticStudent*> searchName(const string &firstName,const string &lastName, DomesticStudent* &head); //to look for students with specified name

    void d_setNext( DomesticStudent* a_next );
    DomesticStudent* d_getNext();
};

typedef DomesticStudent* DomesticPtr;

void d_printList( DomesticPtr head );

DomesticPtr d_findTail( DomesticPtr head );

bool d_trimHeadTail( DomesticPtr* head );

#endif //FINALREPORT_DOMESTICSTUDENT_HPP
