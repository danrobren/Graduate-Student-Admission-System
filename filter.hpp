#ifndef FINALPROJECT_FILTER_HPP
#define FINALPROJECT_FILTER_HPP

#include <iostream>
#include <vector>
#include "InternationalStudent.hpp"
#include "DomesticStudent.hpp"
#include "Student.hpp"
#include "UserIO.hpp"
using namespace std;

class filter
{
public:
    static vector<DomesticStudent*> getFilterResult(DomesticStudent* dHead, Conditions &condition);
    static vector<InternationalStudent*> getFilterResult(InternationalStudent* dHead, Conditions &condition);
    static vector<Student*> getFilterResult(Student* sHead, Conditions &condition);
};


#endif //FINALPROJECT_FILTER_HPP
