#ifndef INTERIMREPORT_STU_SORT_HPP
#define INTERIMREPORT_STU_SORT_HPP

#include <string>
#include <vector>
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
using namespace std;

class Sorting
{
public:
    static const int FIRST_NAME = 0;
    static const int LAST_NAME = 1;
    static const int CGPA = 2;
    static const int RESEARCH_SCORE = 3;
    static const int LANG_SCORE = 4;
    static const int PROVINCE = 5;
    static const int COUNTRY = 6;

    void quickSort(vector<DomesticStudent> &students, int type);
    void quickSort(vector<InternationalStudent> &students, int type);
    void overallSorting(vector<DomesticStudent> &students);
    vector<InternationalStudent> overallSorting(vector<InternationalStudent> &students);
private:
    void swap(vector<DomesticStudent> &students, int index1, int index2);
    int partition(vector<DomesticStudent> &students, int indexPivot, int indexRight, int type);
    void quickSort(vector<DomesticStudent> &students, int indexPivot, int indexRight, int type);

    void swap(vector<InternationalStudent> &students, int index1, int index2);
    int partition(vector<InternationalStudent> &students, int indexPivot, int indexRight, int type);
    void quickSort(vector<InternationalStudent> &students, int indexPivot, int indexRight, int type);
    void mergeSort(vector<DomesticStudent> &students, int indexLeft, int indexRight);
    void merge(vector<DomesticStudent> &students, int indexLeft, int indexMid, int indexRight);
    void mergeSort(vector<InternationalStudent> &students, int indexLeft, int indexRight);
    void merge(vector<InternationalStudent> &students, int indexLeft, int indexMid, int indexRight);
};


#endif //INTERIMREPORT_STU_SORT_HPP