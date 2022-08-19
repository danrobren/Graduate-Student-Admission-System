#include "Student.hpp"
using namespace std;

#ifndef ERROR_HPP_
#define ERROR_HPP_

// forward definition of student classes
class DomesticStudent;
class InternationalStudent;

class error: exception // error check parent class for insertStudent function
{};

class e_nullStudent : public error
{};


// errors in domestic student functions

class d_error: public error
{
protected:
    DomesticStudent* student = NULL;
public:
    DomesticStudent* getStudent();
};

class d_badCGPA : public d_error
{
public:
    d_badCGPA( DomesticStudent* a_student );
};

class d_badResearch : public d_error
{
public:
    d_badResearch( DomesticStudent* a_student );;
};

class d_badProvince : public d_error
{
public:
    d_badProvince( DomesticStudent* a_student );
};

class d_duplicateNode: public d_error
{
public:
    d_duplicateNode( DomesticStudent* a_student );
};


// below are international student error classes

class i_error : public error
{
protected:
    InternationalStudent* student = NULL;
public:
    InternationalStudent* getStudent();
};

class i_badCGPA : public i_error
{
public:
    i_badCGPA( InternationalStudent* a_student );
};

class i_badResearch : public i_error
{
public:
    i_badResearch( InternationalStudent* a_student );;
};

class i_badCountry : public i_error
{
public:
    i_badCountry( InternationalStudent* a_student );
};

class i_duplicateNode: public i_error
{
public:
    i_duplicateNode( InternationalStudent* a_student );
};

class i_badLangScore: public i_error{
public:
    i_badLangScore(InternationalStudent* a_student );
};
#endif //ERROR_HPP
