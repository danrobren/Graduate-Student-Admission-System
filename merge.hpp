//
// Created by Noahh on 2022-07-20.
//

#ifndef FINALPROJECT_MERGE_H
#define FINALPROJECT_MERGE_H

#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
#include "stu_sort.hpp"
#include "ToeflScore.hpp"

using namespace std;

class Merge
{
public:
    //merge functions
    //merge DomesticStudent and InternationalStudent linked lists
    //precondition: both linked lists are sorted
    //merged linked list: sort first by research score, then by CGPA, then DomesticStudent before InternationalStudent
    static Student* mergeLists(DomesticStudent* dHead, InternationalStudent* iHead);

    void addNode(Student** mergedNode, Student** originalNode);

    virtual void listPrint(StudentPtr head,int researchScore_threshold, float cgpa_threshold);
};

class derived : public Merge
{
public:
    //print function
    //uses polymorphism and virtual function for the print
    //expected result: prints out student object information for students admitted to SFU
    //admission requirements: must satisfy both cgpa>=cgpa_threshold and researchScore>=researchScore_threshold
    virtual void listPrint(StudentPtr head, int researchScore_threshold, float cgpa_threshold);
};

#endif //FINALPROJECT_MERGE_H
