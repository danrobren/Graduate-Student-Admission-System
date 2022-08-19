//
// Created by Noahh on 2022-07-20.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
#include "stu_sort.hpp"
#include "ToeflScore.hpp"
#include "merge.hpp"

using namespace std;

void Merge::addNode(Student** mergedNode, Student** originalNode)
{
//    Student* newNode = *originalNode;
//
//    if(newNode != nullptr)
//    {
//        *originalNode = newNode->next;
//
//        newNode->next = *mergedNode;
//
//        *mergedNode = newNode;
//    }
}

Student* Merge::mergeLists(DomesticStudent* dHead, InternationalStudent* iHead)
{
    if( !dHead || !iHead )
    {
        cout << "Null international or domestic list head, aborting merge.";
        return NULL;
    }
    // since each list is sorted to begin with, we can use one list as a base for the other
    // we'll use domesticStudent as the base
    // so we must first go through the whole list and make it a Student* list

    StudentPtr here; StudentPtr head = dHead; // head of new Student* list simple called head
    DomesticPtr next = dHead->d_getNext(); // we keep next as a domestic , so we don't lose access to its next
    head->setNext( next );

    while( next )
    {
        here = next; // current here is the previous next
        next = next->d_getNext(); // move to next pointer, store as an domesticPtr to preserve its next

        here->setNext( next ); // this assigns (Student*) = (DomesticStudent*)
    }

    // now we must insert all the internationalStudents into this list
    StudentPtr ihere = iHead;
    InternationalPtr inext = iHead->i_getNext();

    while( inext )
    {
        here = inext;
        inext = inext->i_getNext();
        here->insertMerged(&head);
    }

    return head;

    //	cout << "\ndomestic head: " << *dHead << endl;
    //	DomesticPtr dhere = dHead;
    //	while( dhere )
    //	{
    //		cout << *dhere << endl;
    //		dhere = dhere->getNext();
    //	}

    //dummyNode to start linked list for adding nodes from linked list inputs
//    Student dummyNode;
//    Student *tail = &dummyNode;
//    dummyNode.next = nullptr;
//
//    while (dHead != nullptr && iHead != nullptr) {
//        //cases for either input linked list running out of student nodes
//        //continues with the rest of the other input linked list
//        if (dHead == nullptr) {
//            tail->next = iHead;
//            break;
//        } else if (iHead == nullptr) {
//            tail->next = dHead;
//            break;
//
//            //compare research score
//            if (dHead->getResearchScore() > iHead->getResearchScore()) {
//                addNode(&(tail->next), &dHead);
//            }
//                //if same research score, compare CGPA
//            else if (dHead->getResearchScore() == iHead->getResearchScore()) {
//                if (dHead->get_cgpa() > iHead->get_cgpa()) {
//                    addNode(&(tail->next), &dHead);
//                }
//                    // if also same CGPA, domesticStudent before InternationalStudent
//                else if (dHead->get_cgpa() == iHead->get_cgpa()) {
//                    addNode(&(tail->next), &dHead);
//                } else {
//                    addNode(&(tail->next), &iHead);
//                }
//            } else {
//                addNode(&(tail->next), &iHead);
//            }
//
//            tail = tail->next;
//        }
//        return (dummyNode.next);
//
//    }
}

//base print function
void Merge::listPrint(StudentPtr head, int researchScore_threshold, float cgpa_threshold)
{
    cout << "print function of base Merge class" << endl;
}

//derived Merge class print function
void derived::listPrint(Student* head, int researchScore_threshold, float cgpa_threshold)
{
    StudentPtr here = head;

    while (here != nullptr)
    {
        if(here->getResearchScore() >= researchScore_threshold && here->get_cgpa() >= cgpa_threshold)
        {
            cout << "Student Name: " << here->getFirstName() << " " << here->getLastName() <<
                 ", Application ID: " << here->getApplicationId() << ", CGPA: " << here->get_cgpa()
                 << ", Research Score: " << here->getResearchScore() << endl;
        }

        here = here->getNext();
    }



}

