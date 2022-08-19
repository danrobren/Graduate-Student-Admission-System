#ifndef FINALPROJECT_USERIO_HPP
#define FINALPROJECT_USERIO_HPP


#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
struct Conditions
{
    bool cgpaConditioned;
    int cgpaCondition;
    vector<float> cgpaVal;

    bool rsConditioned;
    int rsCondition;
    vector<int> rsVal;
    Conditions(const bool &cgpaConditioned,const int &cgpaCondition,const vector<float> &cgpaVal, const bool &rsConditioned,const int &rsCondition,const vector<int> &rsVal);
};

class UserIO
{
private:
    static void filter(const int &type, DomesticStudent *&dHead, InternationalStudent *&iHead);
public:
    static void inputStudent(DomesticStudent* &dHead, InternationalStudent* &iHead, int &studentId);
    static void deleteStudent(DomesticStudent* &dHead, InternationalStudent* &iHead);
    static void searchStudent(DomesticStudent* &dHead, InternationalStudent* &iHead);
    static void printAllStudent(DomesticStudent* &dHead, InternationalStudent* &iHead);
    static void disciplinarySystem(DomesticStudent* &dHead, InternationalStudent* &iHead);
    static void filterStudent(DomesticStudent* &dHead, InternationalStudent* &iHead);
    static int askForInt(istream &i, ostream &o);
    static float askForFloat(istream &i, ostream &o);
    static void startApplication();

};


#endif //FINALPROJECT_USERIO_HPP
