#include <vector>
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
#include "stu_sort.hpp"
using namespace std;

void Sorting::swap(vector<DomesticStudent> &students, int index1, int index2)
{
    DomesticStudent temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
}

int Sorting::partition(vector<DomesticStudent> &students, int indexPivot, int indexRight, int type)
{
    DomesticStudent pivot = students[indexPivot];
    int left = indexPivot;
    int right = indexRight + 1;
    while(left < right)
    {
        if(type == Sorting::RESEARCH_SCORE)
        {
            do{left++;}while(compareResearchScore(students[left], pivot) < 0);
            do{right--;}while(compareResearchScore(students[right], pivot) > 0);
        }
        else if(type == Sorting::CGPA)
        {
            do{left++;}while(compareCGPA(students[left], pivot) < 0);
            do{right--;}while(compareCGPA(students[right], pivot) > 0);
        }
        else if(type == Sorting::FIRST_NAME)
        {
            do{left++;}while(compareFirstName(students[left], pivot) < 0);
            do{right--;}while(compareFirstName(students[right], pivot) > 0);
        }
        else if(type == Sorting::LAST_NAME)
        {
            do{left++;}while(compareLastName(students[left], pivot) < 0);
            do{right--;}while(compareLastName(students[right], pivot) > 0);
        }
        else if(type == Sorting::PROVINCE)
        {
            do{left++;}while(compareProvince(students[left], pivot) < 0);
            do{right--;}while(compareProvince(students[right], pivot) > 0);
        }
//        else if(type == Sorting::GLOBAL)
//        {
//            int leftRS = compareResearchScore(students[left], pivot);
//            int leftCGPA = compareCGPA(students[left], pivot);
//            int leftProvince = compareProvince(students[left], pivot);
//            int rightRS = compareResearchScore(students[right], pivot);
//            int rightCGPA = compareCGPA(students[right], pivot);
//            int rightProvince = compareProvince(students[right], pivot);
//            do{left++;}while(compareResearchScore(students[left], pivot) < 0);
//            do{left++;}while(compareResearchScore(students[left], pivot) == 0 && compareProvince(students[left], pivot) < 0);
//            do{left++;}while(compareResearchScore(students[left], pivot) == 0 && compareProvince(students[left], pivot) == 0 && compareProvince(students[left], pivot) < 0);
//            do{right--;}while(compareResearchScore(students[right], pivot) > 0);
//            do{right--;}while(compareResearchScore(students[right], pivot) == 0 && compareCGPA(students[right], pivot) > 0);
//            do{right--;}while(compareResearchScore(students[right], pivot) == 0 && compareCGPA(students[right], pivot) == 0 && compareProvince(students[right], pivot) > 0);
//        }
        else
        {
            cout << endl << "invalid sorting type!" << endl;
        }
        if(left < right)
            swap(students, left, right);
    }
    swap(students, right, indexPivot);
    return right;
}

void Sorting::quickSort(vector<DomesticStudent> &students, int indexPivot, int indexRight, int type)
{
    if(indexRight <= indexPivot)
        return;
    int newPivot = partition(students, indexPivot, indexRight, type);
    quickSort(students, indexPivot, newPivot - 1, type);
    quickSort(students, newPivot + 1, indexRight, type);
}

void Sorting::quickSort(vector<DomesticStudent> &v, int type)
{
    if(type == LANG_SCORE)
    {
        cout << "Language score sorting can only function with International Students!" << endl;
        return;
    }
    quickSort(v, 0, v.size() - 1, type);
}

void Sorting::swap(vector<InternationalStudent> &students, int index1, int index2)
{
    InternationalStudent temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
}

int Sorting::partition(vector<InternationalStudent> &students, int indexPivot, int indexRight, int type)
{
    InternationalStudent pivot = students[indexPivot];
    int left = indexPivot;
    int right = indexRight + 1;
    while(left < right)
    {
        if(type == Sorting::RESEARCH_SCORE)
        {
            do{left++;}while(compareResearchScore(students[left], pivot) < 0);
            do{right--;}while(compareResearchScore(students[right], pivot) > 0);
        }
        else if(type == Sorting::CGPA)
        {
            do{left++;}while(compareCGPA(students[left], pivot) < 0);
            do{right--;}while(compareCGPA(students[right], pivot) > 0);
        }
        else if(type == Sorting::FIRST_NAME)
        {
            do{left++;}while(compareFirstName(students[left], pivot) < 0);
            do{right--;}while(compareFirstName(students[right], pivot) > 0);
        }
        else if(type == Sorting::LAST_NAME)
        {
            do{left++;}while(compareLastName(students[left], pivot) < 0);
            do{right--;}while(compareLastName(students[right], pivot) > 0);
        }
        else if(type == Sorting::LANG_SCORE)
        {
            do{left++;}while(compareLangScore(students[left], pivot) < 0);
            do{right--;}while(compareLangScore(students[right], pivot) > 0);
        }
        else if(type == Sorting::COUNTRY)
        {
            do{left++;}while(compareCountry(students[left], pivot) < 0);
            do{right--;}while(compareCountry(students[right], pivot) > 0);
        }
//        else if(type == Sorting::GLOBAL)
//        {
//            do{left++;}while(compareResearchScore(students[left], pivot) < 0);
//            do{left++;}while(compareResearchScore(students[left], pivot) == 0 && compareCountry(students[left], pivot) < 0);
//            do{left++;}while(compareResearchScore(students[left], pivot) == 0 && compareCountry(students[left], pivot) == 0 && compareCountry(students[left], pivot) < 0);
//            do{right--;}while(compareResearchScore(students[right], pivot) > 0);
//            do{right--;}while(compareResearchScore(students[right], pivot) == 0 && compareCGPA(students[right], pivot) > 0);
//            do{right--;}while(compareResearchScore(students[right], pivot) == 0 && compareCGPA(students[right], pivot) == 0 && compareCountry(students[right], pivot) > 0);
//        }
        else
        {
            cout << endl << "invalid sorting type!" << endl;
        }
        if(left < right)
            swap(students, left, right);
    }
    swap(students, right, indexPivot);
    return right;
}

void Sorting::quickSort(vector<InternationalStudent> &students, int indexPivot, int indexRight, int type)
{
    if(indexRight <= indexPivot)
        return;
    int newPivot = partition(students, indexPivot, indexRight, type);
    quickSort(students, indexPivot, newPivot - 1, type);
    quickSort(students, newPivot + 1, indexRight, type);
}

void Sorting::quickSort(vector<InternationalStudent> &v, int type)
{
    quickSort(v, 0, v.size() - 1, type);
}

void Sorting::mergeSort(vector<DomesticStudent> &students, int indexLeft, int indexRight)
{
    if(indexLeft >= indexRight)
        return;
    int indexMid = (indexRight - indexLeft) / 2 + indexLeft;

    mergeSort(students, indexLeft, indexMid);
    mergeSort(students, indexMid + 1, indexRight);

    merge(students, indexLeft, indexMid, indexRight);
}

void Sorting::merge(vector<DomesticStudent> &students, int indexLeft, int indexMid, int indexRight)
{
    vector<DomesticStudent> v1, v2;
    for(int i = 0; i < indexMid - indexLeft + 1; ++i)
        v1.push_back(students[indexLeft + i]);
    for(int i = 0; i < indexRight - indexMid; ++i)
        v2.push_back(students[indexMid + 1 + i]);

    int i = 0;
    int j = 0;
    int k = indexLeft;
    while(i < v1.size() && j < v2.size())
    {
        if(compareResearchScore(v1[i],v2[j]) < 0)
        {
            students[k] = v1[i];
            i++;
        }
        else if(compareResearchScore(v1[i],v2[j]) == 0)
        {
            if(compareCGPA(v1[i],v2[j]) < 0)
            {
                students[k]=v1[i];
                i++;
            }
            else if(compareCGPA(v1[i],v2[j]) == 0)
            {
                if(compareProvince(v1[i],v2[j]) < 0)
                {
                    students[k]=v1[i];
                    i++;
                }
                else
                {
                    students[k]=v2[j];
                    j++;
                }
            }
            else
            {
                students[k]=v2[j];
                j++;
            }
        }
        else
        {
            students[k]=v2[j];
            j++;
        }
        k++;
    }

    while(i < v1.size())
    {
        students[k]=v1[i];
        i++;
        k++;
    }
    while(j < v2.size())
    {
        students[k]=v2[j];
        j++;
        k++;
    }
}

void Sorting::overallSorting(vector<DomesticStudent> &students)
{
    mergeSort(students, 0, students.size() - 1);
}

void Sorting::mergeSort(vector<InternationalStudent> &students, int indexLeft, int indexRight)
{
    if(indexLeft >= indexRight)
        return;
    int indexMid = (indexRight - indexLeft) / 2 + indexLeft;

    mergeSort(students, indexLeft, indexMid);
    mergeSort(students, indexMid + 1, indexRight);

    merge(students, indexLeft, indexMid, indexRight);
}

void Sorting::merge(vector<InternationalStudent> &students, int indexLeft, int indexMid, int indexRight)
{
    vector<InternationalStudent> v1, v2;
    for(int i = 0; i < indexMid - indexLeft + 1; ++i)
        v1.push_back(students[indexLeft + i]);
    for(int i = 0; i < indexRight - indexMid; ++i)
        v2.push_back(students[indexMid + 1 + i]);

    int i = 0;
    int j = 0;
    int k = indexLeft;
    while(i < v1.size() && j < v2.size())
    {
        if(compareResearchScore(v1[i],v2[j]) < 0)
        {
            students[k] = v1[i];
            i++;
        }
        else if(compareResearchScore(v1[i],v2[j]) == 0)
        {
            if(compareCGPA(v1[i],v2[j]) < 0)
            {
                students[k] = v1[i];
                i++;
            }
            else if(compareCGPA(v1[i],v2[j]) == 0)
            {
                if(compareCountry(v1[i],v2[j]) < 0)
                {
                    students[k] = v1[i];
                    i++;
                }
                else
                {
                    students[k] = v2[j];
                    j++;
                }
            }
            else
            {
                students[k] = v2[j];
                j++;
            }
        }
        else
        {
            students[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < v1.size())
    {
        students[k] = v1[i];
        i++;
        k++;
    }
    while(j < v2.size())
    {
        students[k] = v2[j];
        j++;
        k++;
    }
}

vector<InternationalStudent> Sorting::overallSorting(vector<InternationalStudent> &students)
{
    vector<InternationalStudent> v;
    for(const InternationalStudent& i: students)
        if(!i.getLanguageScore().isDroppable())
            v.push_back(i);
    mergeSort(v, 0, v.size() - 1);
    return v;
}






