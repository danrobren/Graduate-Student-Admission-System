//
// Created by larry on 25/06/2022.
//

#ifndef FINALREPORT_FILEREADER_HPP
#define FINALREPORT_FILEREADER_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
#include "Student.hpp"

using namespace std;

struct StudentBundle
{
    //vector<DomesticStudent> domestic;
    //vector<InternationalStudent> international;
    DomesticPtr dList;
    DomesticPtr dTail;
    InternationalPtr iList;
    InternationalPtr iTail;
    int maxStudentID;
};

class FileReader
{
public:
    static StudentBundle readFile();
};




#endif //FINALREPORT_FILEREADER_HPP
