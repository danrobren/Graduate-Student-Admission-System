#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "FileReader.hpp"
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
#include "stu_sort.hpp"
#include "ToeflScore.hpp"
#include "error.hpp"
#include "merge.hpp"
#include "UserIO.hpp"
#include "UnitTest.hpp"

using namespace std;


int main() {

    cout << "[0] Unit Test" << endl;
    cout << "[1] Start Application" << endl;
    cout << "[else] Exit" << endl;
    int in = UserIO::askForInt(cin, cout);
    if(in == 1)
        UserIO::startApplication();
    else if(in == 0)
    {
        UnitTest::startTest();
    }
    return 0;
}




