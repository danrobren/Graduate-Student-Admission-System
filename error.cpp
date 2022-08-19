#include "error.hpp"

// domestic student error fucntions

d_badCGPA::d_badCGPA( DomesticStudent* a_student )
{
    student = a_student;
}

d_badResearch::d_badResearch( DomesticStudent* a_student )
{
    student = a_student;
}

d_badProvince::d_badProvince( DomesticStudent* a_student )
{
    student = a_student;
}

d_duplicateNode::d_duplicateNode( DomesticStudent* a_student )
{
    student = a_student;
}

DomesticStudent* d_error::getStudent()
{
    return student;
}

// international student error functions

i_badCGPA::i_badCGPA( InternationalStudent* a_student )
{
    student = a_student;
}

i_badResearch::i_badResearch( InternationalStudent* a_student )
{
    student = a_student;
}

i_badCountry::i_badCountry( InternationalStudent* a_student )
{
    student = a_student;
}

i_duplicateNode::i_duplicateNode( InternationalStudent* a_student )
{
    student = a_student;
}

InternationalStudent* i_error::getStudent()
{
    return student;
}

i_badLangScore::i_badLangScore(InternationalStudent *a_student)
{
    student = a_student;
}
