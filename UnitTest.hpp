#ifndef FINALPROJECT_UNITTEST_HPP
#define FINALPROJECT_UNITTEST_HPP


#include "InternationalStudent.hpp"
#include "DomesticStudent.hpp"
#include "Student.hpp"


class UnitTest
{
public:
    static void insertTest(DomesticStudent* &dHead, InternationalStudent* &iHead, int &studentId);
    static void deleteTest(DomesticStudent* &dHead, InternationalStudent* &iHead);
    static void trimTest(DomesticStudent* &dHead, InternationalStudent* &iHead);
    static void startTest();
};


#endif //FINALPROJECT_UNITTEST_HPP
