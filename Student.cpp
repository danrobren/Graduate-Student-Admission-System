//
// Created by larry on 18/06/2022.
//

#include "Student.hpp"
#include "UserIO.hpp"


Student::Student()
{
    firstName = "unknown";
    lastName = "unknown";
    cgpa = -1.0;
    researchScore = -1;
    applicationId = -1;
    next = nullptr;
    strikes = 0;
}

Student::Student(const Student &student):Student(student.firstName, student.lastName,student.cgpa,
                                                 student.researchScore, student.applicationId)
{
    strikes = 0;
}

Student::Student(const string &firstNameIn, const string &lastNameIn, const float &cgpaIn, const int &researchScoreIn, const int &applicationIdIn)
{
    firstName = firstNameIn;
    lastName = lastNameIn;
    cgpa = cgpaIn;
    researchScore = researchScoreIn;
    applicationId = applicationIdIn;
    next = nullptr;
    strikes = 0;
}

int Student::getType() const
{
    return 0;
}

string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

float Student::get_cgpa() const
{
    return cgpa;
}

int Student::getResearchScore() const
{
    return researchScore;
}

int Student::getApplicationId() const
{
    return applicationId;
}

void Student::setFirstName(const string &firstNameIn)
{
    firstName = firstNameIn;
}

void Student::setLastName(const string &lastNameIn)
{
    lastName = lastNameIn;
}

void Student::set_cgpa(const float &cgpaIn)
{
    cgpa = cgpaIn;
}

void Student::setResearchScore(const int &researchScoreIn)
{
    researchScore = researchScoreIn;
}

//void Student::setApplicationId(const int &applicationIdIn)
//{
//    applicationId = applicationIdIn;
//}

string Student::toString() const
{
    return "Student: " + firstName + " " + lastName + ", Application ID: " + to_string(applicationId) + ", CGPA: " + to_string(cgpa).substr(0,4) + ", Research Score: " + to_string(researchScore);
}

ostream &operator<<(ostream &os, const Student &student)
{
    os << student.toString();
    return os;
}

bool Student::insertMerged( Student** head )
{
    if(!*head) return false;

    StudentPtr prev = NULL, here = *head;

    if(!here) // head is the only node case
    {
        prev->next = this;
    }

    while (1)
    {
        if (here->getResearchScore() == researchScore)
        {
            if (here->getResearchScore() == researchScore && here->get_cgpa() == cgpa)
            {
                if (!prev && here == *head) // inserting head node case
                {
                    this->next = here;
                    *head = this;
                    return 1;
                }

                this->next = here;
                prev->next = this;
                return 1;
            }
            if (here->getResearchScore() == researchScore && here->get_cgpa() > cgpa)
            {
                if (!prev && here == *head) // inserting head node case
                {
                    this->next = here;
                    *head = this;
                    return 1;
                }
                this->next = here;
                prev->next = this;
                return 1;
            }
        }
        if (here->getResearchScore() > researchScore)
        {
            if(!prev && here == *head) // inserting head node case
            {
                this->next = here;
                *head = this;
                return 1;
            }
            this->next = here;
            prev->next = this;
            return 1;
        }

        prev = here;
        here = here->next;

        // inserting the last node in the list case
        if (!here)
        {
            this->next = here;
            prev->next = this;
            return 1;
        }
    }
}

bool Student::operator==(const Student &rhs) const
{
    return firstName == rhs.firstName &&
           lastName == rhs.lastName &&
           cgpa == rhs.cgpa &&
           researchScore == rhs.researchScore &&
           applicationId == rhs.applicationId;
}


int compareResearchScore(const Student& stu1, const Student& stu2) {
    if (stu1.researchScore > stu2.researchScore) {
        return 1;
    }
    else if (stu1.researchScore == stu2.researchScore) {
        return 0;
    }

    else {
        return -1;
    }
}

int compareCGPA(const Student& stu1, const Student& stu2) {
    if (stu1.cgpa > stu2.cgpa) {
        return 1;
    }
    else if (stu1.cgpa == stu2.cgpa) {
        return 0;
    }

    else {
        return -1;
    }
}

int compareFirstName(const Student& stu1, const Student& stu2) {
    if (stu1.firstName > stu2.firstName) {
        return 1;
    }
    else if (stu1.firstName == stu2.firstName) {
        return 0;
    }

    else {
        return -1;
    }
}

int compareLastName(const Student& stu1, const Student& stu2) {
    if (stu1.lastName > stu2.lastName) {
        return 1;
    }
    else if (stu1.lastName == stu2.lastName) {
        return 0;
    }

    else {
        return -1;
    }
}

//helper funcs for name search
//to check if the string does not contains any numeric character
bool checkString(string name) {
    if (name == "") {
        return false;;
    }
    for (int i = 0; i < name.length(); i++) {
        if (name[i] >= 48 && name[i] <= 57) {
            cout << "Error: name has numeric value in it.\n";
            return false;;
        }
    }
    return true;
}

//to lowercase the string
string toLowerString(string name) {
    string ans = "";
    for (int i = 0; i < name.length(); i++) {
        ans += tolower(name[i]);    //for each character convert to lowercase and add it to ans
    }
    //return the ans
    return ans;
}

Student* Student::getNext()
{
    return next;
}

void Student::setNext( Student* a_next )
{
    next = a_next;
}

vector<Student *> Student::searchA(int id, Student *head)
{
    if (id < 20220000) {
        cout << "invalid id" << endl;
        return {};
    }
    if (head == nullptr) {
        //case list is empty
        cout << "Student List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<Student*> v;
        Student* curr = head;


        while (curr != nullptr) {
            if (curr->getApplicationId() == id) {
                v.push_back(curr);
            }
            curr = curr->getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the Student list" << endl;
        }
        return v;
    }
}

vector<Student *> Student::searchR(int score, Student *head)
{
    if (score < 0 || score>100) {
        cout << "invalid research score" << endl;
        return {};
    }
    if (head == nullptr) {
        //case list is empty
        cout << "Student List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<Student*> v;
        Student* curr = head;


        while (curr != nullptr) {
            if (curr->getResearchScore() == score) {
                v.push_back(curr);
            }
            curr = curr->getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the Student list" << endl;
        }
        return v;
    }
}

vector<Student *> Student::searchC(float cgpaIn, Student *head)
{
    if (cgpaIn < 0 || cgpaIn>4.33) {
        cout << "invalid cgpa" << endl;
        return {};
    }
    if (head == nullptr) {
        //case list is empty
        cout << "Student List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<Student*> v;
        Student* curr = head;

        while (curr != nullptr) {
            if (curr->get_cgpa() == cgpaIn) {
                v.push_back(curr);
            }
            curr = curr->getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the Student list" << endl;
        }
        return v;
    }
}

vector<Student *> Student::searchName(const string &firstName,const  string &lastName, Student* &head)
{
    if (!checkString(firstName) || !checkString(lastName)) { //checking it has no number
        cout << "invalid name" << endl;
        return {};
    }
    if (head == nullptr) {
        //case list is empty
        cout << "Student List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<Student*> v;
        Student* curr = head;

        while (curr != nullptr) {
            if (toLowerString(curr->getFirstName()) == toLowerString(firstName) && toLowerString(curr->getLastName()) == toLowerString(lastName)) {
                v.push_back(curr);
            }
            curr = curr->getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the Student list" << endl;
        }
        return v;
    }
}


StudentPtr i_findTail( StudentPtr head )
{
    if(!head) return NULL;
    StudentPtr here = head;
    while( here->getNext() ) here = here->getNext();
    return here;
}

bool trimHeadTail( StudentPtr* head )
{
    if(!head) return false;

    StudentPtr realHead = *head;

    if(!realHead->getNext())
    {
        delete head;
        return 1;
    }

    StudentPtr prev = realHead, here = realHead->getNext();
    while( here->getNext() )
    {
        prev = here;
        here = here->getNext();
    }
    delete here;
    prev->setNext(NULL);

    StudentPtr temp = realHead->getNext();
    delete *head;
    *head = temp;
    return 1;
}

void addStrike( StudentPtr head )
{
    if(!head)
    {
        cout << "invalid addStrike call: null head";
        return;
    }

    int target_id = 0;
    cout << "\nNote that disciplinary strikes are permanent and non-removable!\nPlease enter the application ID of the student receiving the disciplinary strike: ";
    while(1)
    {
        target_id = UserIO::askForInt(cin, cout);
        if( target_id <= 20220000 || target_id > 20230000 )
        {
            cout << "\nValid application IDs are within [20220000, 2023000), please try again: ";
            continue;
        }
        break;
    }

    StudentPtr here = head;
    while(here)
    {
        if(here->getApplicationId() == target_id)
        {
            here->incrementStrike();
            cout << "The student below now has: " << here->getStrike() << " disciplinary strikes\n" << *here << endl;
            return;
        }
        here = here->getNext();
    }
    cout << "\nA student with id: " << target_id << " was not found in the list!\n\n";
}

void disciplinaryInquiry( Student* head )
{
    if(!head)
    {
        cout << "invalid disciplinaryInquiry call: null head";
        return;
    }

    cout << "\nPlease enter the application ID of the student in question: ";
    int target_id = 0;
    while(1)
    {
        target_id = UserIO::askForInt(cin, cout);
        if( target_id <= 20220000 || target_id > 20230000 )
        {
            cout << "\nValid application IDs are within [20220000, 2023000), please try again: ";
            continue;
        }
        break;
    }

    StudentPtr here = head;
    while(here != nullptr)
    {
        if(here->getApplicationId() == target_id)
        {
            cout << "The student below has: " << here->getStrike() << " disciplinary strikes\n" << *here << endl;
            return;
        }
        here = here->getNext();
    }
    cout << "\nA student with id: " << target_id << " was not found in the list!";
}

void Student::incrementStrike()
{
    strikes++;
}

int Student::getStrike()
{
    return strikes;
}