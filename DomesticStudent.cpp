//
// Created by larry on 18/06/2022.
//

#include "DomesticStudent.hpp"

DomesticStudent::DomesticStudent() :Student()
{
    province = "unknown";
    next = nullptr;
}

DomesticStudent::DomesticStudent(const DomesticStudent& student) : DomesticStudent(student.firstName, student.lastName, student.cgpa,
                                                                                   student.researchScore, student.applicationId, student.province)
{
    next = nullptr;
}

DomesticStudent::DomesticStudent(const Student& student, const string& provinceIn) : Student(student)
{
    province = provinceIn;
    next = nullptr;
}

DomesticStudent::DomesticStudent(const string& firstNameIn, const string& lastNameIn, const float& cgpaIn,
                                 const int& researchScoreIn, const int& applicationIdIn, const string& provinceIn) : Student(firstNameIn, lastNameIn, cgpaIn, researchScoreIn, applicationIdIn)
{
    province = provinceIn;
    next = nullptr;
}

int DomesticStudent::getType() const
{
    return 1;
}

string DomesticStudent::getProvince() const
{
    return province;
}

void DomesticStudent::setProvince(const string& provinceIn)
{
    province = provinceIn;
}

string DomesticStudent::toString() const
{
    return Student::toString() + ", province: " + province;
}

ostream& operator<<(ostream& os, const DomesticStudent& student)
{
    os << student.toString();
    return os;
}

bool DomesticStudent::operator==(const DomesticStudent& student) const
{
    return static_cast<const Student&>(*this) == static_cast<const Student&>(student) &&
           province == student.province;
}

bool DomesticStudent::operator!=(const DomesticStudent& rhs) const
{
    return !(rhs == *this);
}

int compareProvince(const DomesticStudent& stu1, const DomesticStudent& stu2)
{
    string province1 = stu1.getProvince();
    string province2 = stu2.getProvince();
    if (province1 > province2) {
        return 1;
    }
    else if (province1 == province2) {
        return 0;
    }
    else {
        return -1;
    }
}

bool DomesticStudent::insertDomestic(DomesticPtr &head) throw(d_error)
{
    if (!head) return 0;

    if (!this) throw (e_nullStudent());

    // may not insert duplicate nodes
    if (searchDomestic(head)) throw(d_duplicateNode(this));

    // valid research scores are between 0 and 100, throw an error if out of bounds
    if (researchScore > 100 || 0 > researchScore) throw(d_badResearch(this));

    // valid CGPA scores are 0 to 4.33
    if (cgpa > 4.33 || 0 > cgpa) throw(d_badCGPA(this));

    // valid provinces are  NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU
    int n_provinces = 13;
    bool p_valid = false;
    string validProvinces[13] = { "NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU" };
    for (int i = 0; i < n_provinces; i++)
    {
        if (province == validProvinces[i]) p_valid = true;
    }
    if (!p_valid) throw(d_badProvince(this));

    DomesticPtr prev = nullptr;
    DomesticPtr here = head;

    while (1)
    {
        if (here->getResearchScore() == researchScore)
        {
            if (here->getResearchScore() == researchScore && here->get_cgpa() == cgpa)
            {
                if (here->getResearchScore() == researchScore && here->get_cgpa() == cgpa && here->getProvince() > province)
                {
                    if (!prev && here == head) // inserting head node case
                    {
                        next = here;
                        head = this;
                        return 1;
                    }
                    next = here;
                    prev->d_setNext( this );
                    return 1;
                }
            }
            if (here->getResearchScore() == researchScore && here->get_cgpa() > cgpa)
            {
                if (!prev && here == head) // inserting head node case
                {
                    next = here;
                    head = this;
                    return 1;
                }
                next = here;
                prev->d_setNext( this );
                return 1;
            }
        }

        if (here->getResearchScore() > researchScore)
        {
            if (!prev && here == head) // inserting head node case
            {
                next = here;
                head = this;
                return 1;
            }
            next = here;
            prev->d_setNext(this);
            return 1;
        }

        prev = here;
        here = here->d_getNext();

        // inserting the last node in the list case
        if (!here)
        {
            next = here;
            prev->d_setNext( this );
            return 1;
        }
    }
}

bool DomesticStudent::deleteDomestic(DomesticStudent* &head)
{
    if(this == head)
    {
        DomesticStudent* deletable = head;
        head = head->d_getNext();
        delete deletable;
        return true;
    }
    else if (searchDomestic(head))
    {
        DomesticPtr prev, here = head;
        while (here)
        {
            if (here == this)
            {
                prev->next = here->next;
                delete here;
                return 1;
            }
            prev = here;
            here = here->next;
        }
    }
    return 0;
}

bool DomesticStudent::searchDomestic(DomesticStudent* head)
{
    DomesticPtr here = head;
    while (here)
    {
        if (here == this) return 1;
        here = here->d_getNext();
    }
    return 0;
}



//to look for objects with given application id in domestic list
vector<DomesticStudent*> DomesticStudent::searchA(int id, DomesticPtr head) {
    if (id < 20220000) {
        cout << "invalid id" << endl;
        return {};
    }
    if (head == nullptr) {
        //case list is empty
        cout << "Domestic  List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<DomesticStudent*> v;
        DomesticPtr curr = head;

        while (curr != nullptr) {
            if (curr->getApplicationId() == id) {
                v.push_back(curr);
            }
            curr = curr->d_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the Domestic list" << endl;
        }
        return v;
    }
}


//to look for nodes with given score
vector<DomesticStudent*> DomesticStudent::searchR(int score, DomesticPtr head) {
    if (score < 0 || score>100) {
        cout << "invalid research score" << endl;
        return {};
    }
    if (head == nullptr) {
        //case list is empty
        cout << "List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<DomesticStudent*> v;
        DomesticPtr curr = head;

        while (curr != nullptr) {
            if (curr->getResearchScore() == score) {
                v.push_back(curr);

            }
            curr = curr->d_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the list" << endl;
        }
        return v;
    }
}

//to look for objects with given cgpa
vector<DomesticStudent*> DomesticStudent::searchC(float cgpa, DomesticPtr head) {
    if (cgpa < 0 || cgpa>4.33) {
        cout << "invalid cgpa" << endl;
        return {};
    }
    if (head == nullptr) {
        //case list is empty
        cout << "List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<DomesticStudent*> v;
        DomesticPtr curr = head;

        while (curr != nullptr) {
            if (curr->get_cgpa() == cgpa) {
                v.push_back(curr);

            }
            curr = curr->d_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the list" << endl;
        }
        return v;
    }
}

//to look for objects with given full name
vector<DomesticStudent*> DomesticStudent::searchName(const string &firstName,const string &lastName, DomesticPtr &head) {
    if (!checkString(firstName) || !checkString(lastName)) { //checking it has no number
        cout << "invalid name" << endl;
        return {};
    }

    if (head == nullptr) {
        //case list is empty
        cout << "List is Empty" << endl;
        return {};
    }
    else {
        //case list has atleast one object
        vector<DomesticStudent*> v;
        DomesticPtr curr = head;

        while (curr != nullptr) {
            if (toLowerString(curr->getFirstName()) == toLowerString(firstName) && toLowerString(curr->getLastName()) == toLowerString(lastName)) {
                v.push_back(curr);
            }
            curr = curr->d_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the list" << endl;
        }
        return v;
    }
}

DomesticPtr DomesticStudent::d_getNext()
{
    return next;
}

void DomesticStudent::d_setNext( DomesticPtr a_next )
{
    next = a_next;
}

bool DomesticStudent::insert(DomesticStudent *&head)
{
    try
    {
        return insertDomestic(head);
    }
    catch(d_badCGPA &e )
    {
        DomesticPtr e_student = e.getStudent();
        cout << endl << "Invalid CGPA ( " << e_student->get_cgpa() << " ) for applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << endl;
        cout << "Valid CGPA values are within [4.33, 0.00]" << endl;
        cout << "This student was not added to the list" << endl;
    }
    catch(d_badResearch &e )
    {
        DomesticPtr e_student = e.getStudent();
        cout << endl << "Invalid research score ( " << e_student->getResearchScore() << " ) for applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << endl;
        cout << "Valid research scores are within [100, 0]" << endl;
        cout << "This student was not added to the list" << endl;
    }
    catch(d_badProvince &e )
    {
        DomesticPtr e_student = e.getStudent();
        cout << endl << "Invalid province ( " << e_student->getProvince() << " ) for applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << endl;
        cout << "Valid provinces are: NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU" << endl;
        cout << "This student was not added to the list" << endl;
    }
    catch(d_duplicateNode &e )
    {
        // note that this exception is thrown only when you attempt to include the same NODE twice
        // not if two students have the same name or even all the same data
        // only thrown if the memory addresses of student are the same
        DomesticPtr e_student = e.getStudent();
        cout << "Applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << " is already in the list!" << endl;
    }
    catch(e_nullStudent &e )
    {
        cout << "Null student error." << endl;
    }
    catch(...)
    {
        cout << "unknown error reading from domestic-stu.txt";
    }
    return false;
}

void d_printList( DomesticPtr head )
{
    DomesticPtr here = head;
    while( here )
    {
        cout << *here << endl;
        here = here->d_getNext();
    }
    return;
}

DomesticPtr d_findTail( DomesticPtr head )
{
    if(!head) return NULL;
    DomesticPtr here = head;
    while( here->d_getNext() ) here = here->d_getNext();
    return here;
}

bool d_trimHeadTail( DomesticPtr* head )
{
    if(!head) return false;

    DomesticPtr realHead = *head;

    if(!realHead->d_getNext())
    {
        delete head;
        return 1;
    }

    DomesticPtr prev = realHead, here = realHead->d_getNext();
    while( here->d_getNext() )
    {
        prev = here;
        here = here->d_getNext();
    }
    delete here;
    prev->d_setNext(NULL);

    DomesticPtr temp = realHead->d_getNext();
    delete *head;
    *head = temp;
    return 1;
}