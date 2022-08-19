#include <vector>
#include "InternationalStudent.hpp"

InternationalStudent::InternationalStudent(): Student()
{
    country = "unknown";
    languageScore = ToeflScore();
    next = nullptr;
}

InternationalStudent::InternationalStudent(const InternationalStudent &student): InternationalStudent(student.firstName, student.lastName,student.cgpa,
                                                                                                      student.researchScore, student.applicationId, student.country, ToeflScore(student.languageScore))
{
    next = nullptr;
}

InternationalStudent::InternationalStudent(const Student &student, const string &countryIn, const ToeflScore &lang): Student(student)
{
    country = countryIn;
    languageScore = ToeflScore(lang);
    next = nullptr;
}

InternationalStudent::InternationalStudent(const string &firstNameIn, const string &lastNameIn, const float &cgpaIn,
                                           const int &researchScoreIn, const int &applicationIdIn,
                                           const string &countryIn, const ToeflScore &lang): Student(firstNameIn, lastNameIn, cgpaIn, researchScoreIn, applicationIdIn)
{
    country = countryIn;
    languageScore = ToeflScore(lang);
    next = nullptr;
}

int InternationalStudent::getType() const
{
    return 2;
}

string InternationalStudent::getCountry() const
{
    return country;
}

ToeflScore InternationalStudent::getLanguageScore() const
{
    return languageScore;
}

void InternationalStudent::setCountry(const string &countryIn)
{
    country = countryIn;
}

void InternationalStudent::setLanguageScore(const ToeflScore &lang)
{
    languageScore = ToeflScore(lang);
}

string InternationalStudent::toString() const
{
    return Student::toString() + ", Country: " + country + "\n" + languageScore.toString();
}

ostream &operator<<(ostream &os, const InternationalStudent &student)
{
    os << student.toString();
    return os;
}

bool InternationalStudent::operator==(const InternationalStudent &student) const
{
    return static_cast<const Student &>(*this) == static_cast<const Student &>(student) &&
           country == student.country &&
           languageScore == student.languageScore;
}

bool InternationalStudent::operator!=(const InternationalStudent &student) const
{
    return !(student == *this);
}

int compareLangScore(const InternationalStudent &stu1, const InternationalStudent &stu2)
{
    int score1 = stu1.getLanguageScore().getTotal();
    int score2 = stu2.getLanguageScore().getTotal();
    if (score1 > score2) {
        return 1;
    }
    else if (score1 == score2) {
        return 0;
    }
    else {
        return -1;
    }
}

int compareCountry(const InternationalStudent &stu1, const InternationalStudent &stu2)
{
    string country1 = stu1.getCountry();
    string country2 = stu2.getCountry();
    if (country1 > country2) {
        return 1;
    }
    else if (country1 == country2) {
        return 0;
    }
    else {
        return -1;
    }
}

bool InternationalStudent::insertInternational( InternationalPtr &head ) throw( i_error )
{
    if( !head )
    {
        head = this;
        return true;
    }
    if( !this )
        throw ( e_nullStudent() );

    // may not insert duplicate nodes
    if( searchInternational( head ) )
        throw( i_duplicateNode( this ) );

    // valid research scores are between 0 and 100, throw an error if out of bounds
    if( researchScore > 100 || 0 > researchScore )
        throw( i_badResearch( this ) );

    // valid CGPA scores are 0 to 4.33
    if( cgpa > 4.33 || 0 > cgpa )
        throw( i_badCGPA( this ) );

    if( country == "Idian" )
        country = "India"; // fix international-st.txt typo

    //int n_countries = 4;
    bool c_valid = false;
    string validCountries[4] = {"China", "India", "Iran", "Korea"};
    for( int i = 0; i < 4; i++ )
    {
        if( country == validCountries[i] )
            c_valid = true;
    }

    if( !c_valid )
        throw( i_badCountry( this ) );

    if(languageScore.getListening() < 20||languageScore.getWriting() < 20||languageScore.getReading() < 20||languageScore.getSpeaking() < 20||languageScore.getTotal() < 93)
        throw( i_badLangScore(this));

    InternationalPtr prev = nullptr;
    InternationalPtr here = head;

    while( 1 )
    {
        if( here->getResearchScore() == researchScore )
        {
            if( here->getResearchScore() == researchScore && here->get_cgpa() == cgpa )
            {
                if( here->getResearchScore() == researchScore && here->get_cgpa() == cgpa && here->getCountry() > country )
                {
                    if( !prev && here == head) // inserting head node case
                    {
                        next = here;
                        head = this;
                        return 1;
                    }
                    next = here;
                    prev->i_setNext( this );
                    return 1;
                }
            }
            if( here->getResearchScore() == researchScore && here->get_cgpa() > cgpa )
            {
                if( !prev && here == head) // inserting head node case
                {
                    next = here;
                    head = this;
                    return 1;
                }
                next = here;
                prev->i_setNext( this );
                return 1;
            }
        }

        if( here->getResearchScore() > researchScore )
        {
            if( !prev && here == head) // inserting head node case
            {
                next = here;
                head = this;
                return 1;
            }
            next = here;
            prev->i_setNext( this );
            return 1;
        }

        prev = here;
        here = here->i_getNext();

        // inserting the last node in the list case
        if( !here )
        {
            this->next = here;
            prev->next = this;
            return 1;
        }
    }
}

bool InternationalStudent::deleteInternational( InternationalStudent* &head )
{
    if(this == head)
    {
        InternationalStudent* deletable = head;
        head = head->i_getNext();
        delete deletable;
        return true;
    }
    if( searchInternational( head ) )
    {
        InternationalPtr prev, here = head;
        while( here )
        {
            if( here == this )
            {
                prev->next = here->next;
                delete here;
                return 1;
            }
            prev = here;
            here = here->next;
        }
    }
    else return 0;
}

bool InternationalStudent::searchInternational( InternationalPtr head )
{
    InternationalPtr here = head;
    while( here )
    {
        if( here == this ) return 1;
        here = here->i_getNext();
    }
    return 0;
}

//to look for objects with given application id in domestic list
vector<InternationalStudent*> InternationalStudent::searchA(int id, InternationalPtr head) {
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
        vector<InternationalStudent*> v;
        InternationalPtr curr = head;

        while (curr != NULL) {
            if (curr->getApplicationId() == id) {
                v.push_back(curr);
            }
            curr = curr->i_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the Domestic list" << endl;
        }
        return v;
    }
}


//to look for nodes with given score
vector<InternationalStudent*> InternationalStudent::searchR(int score, InternationalPtr head) {
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
        vector<InternationalStudent*> v;
        InternationalPtr curr = head;

        while (curr != nullptr) {
            if (curr->getResearchScore() == score) {
                v.push_back(curr);
            }
            curr = curr->i_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the list" << endl;
        }
        return v;
    }
}

//to look for objects with given cgpa
vector<InternationalStudent*> InternationalStudent::searchC(float cgpa, InternationalPtr head) {
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
        vector<InternationalStudent*> v;
        InternationalPtr curr = head;

        while (curr != nullptr) {
            if (curr->get_cgpa() == cgpa) {
                v.push_back(curr);
            }
            curr = curr->i_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the list" << endl;
        }
        return v;
    }
}

//to look for objects with given full name
vector<InternationalStudent*> InternationalStudent::searchName(const string &firstName,const string &lastName, InternationalPtr &head) {
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
        vector<InternationalStudent*> v;
        InternationalPtr curr = head;


        while (curr != nullptr) {
            if (toLowerString(curr->getFirstName()) == toLowerString(firstName) && toLowerString(curr->getLastName()) == toLowerString(lastName)) {
                v.push_back(curr);
            }
            curr = curr->i_getNext();
        }

        if (v.empty()) {
            //case no match found
            cout << "No Match Found in the list" << endl;
        }
        return v;
    }
}

void InternationalStudent::i_setNext( InternationalPtr a_next )
{
    next = a_next;
}

InternationalPtr InternationalStudent::i_getNext()
{
    return next;
}

bool InternationalStudent::insert(InternationalStudent *&head)
{
    try
    {
        return insertInternational(head);
    }
    catch(i_badCGPA &e)
    {
        InternationalPtr e_student = e.getStudent();
        cout << endl << "Invalid CGPA ( " << e_student->get_cgpa() << " ) for applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << endl;
        cout << "Valid CGPA values are within [4.33, 0.00]" << endl;
        cout << "This student was not added to the list" << endl;
    }
    catch( i_badResearch &e )
    {
        InternationalPtr e_student = e.getStudent();
        cout << endl << "Invalid research score ( " << e_student->getResearchScore() << " ) for applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << endl;
        cout << "Valid research scores are within [100, 0]" << endl;
        cout << "This student was not added to the list" << endl;
    }
    catch( i_badCountry &e )
    {
        InternationalPtr e_student = e.getStudent();
        cout << endl << "Invalid country ( " << e_student->getCountry() << " ) for applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << endl;
        cout << "Valid countries are: China, India, Iran, Korea" << endl;
        cout << "This student was not added to the list" << endl;
    }
    catch( i_duplicateNode &e )
    {
        // note that this exception is thrown only when you attempt to include the same NODE twice
        // not if two students have the same name or even all the same data
        // only thrown if the memory addresses of student are the same
        InternationalPtr e_student = e.getStudent();
        cout << "Applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << " is already in the list!" << endl;
    }
    catch( e_nullStudent &e )
    {
        cout << "Null student error." << endl;
    }
    catch(i_badLangScore &e)
    {
        InternationalPtr e_student = e.getStudent();
        cout << endl << "Invalid or unsatisfied Toefl score ( " << e_student->getLanguageScore() << " ) for applicant: " << e_student->getFirstName() << " " <<  e_student->getLastName() << endl;
        cout << "Listening/Writing/Reading/Speaking need to be >= 20 in addition to >= 93 in total" << endl;
        cout << "This student was not added to the list" << endl;
    }
    catch(...)
    {
        cout << "unknown error reading from domestic-stu.txt";
    }
    return false;
}

void i_printList( InternationalPtr head )
{
    InternationalPtr here = head;
    while( here )
    {
        cout << *here << endl;
        here = here->i_getNext();
    }
    return;
}

InternationalPtr i_findTail( InternationalPtr head )
{
    if(!head) return NULL;
    InternationalPtr here = head;
    while( here->i_getNext() ) here = here->i_getNext();
    return here;
}

bool i_trimHeadTail( InternationalPtr* head )
{
    if(!head) return false;

    InternationalPtr realHead = *head;

    if(!realHead->i_getNext())
    {
        delete head;
        return 1;
    }

    InternationalPtr prev = realHead, here = realHead->i_getNext();
    while( here->i_getNext() )
    {
        prev = here;
        here = here->i_getNext();
    }
    delete here;
    prev->i_setNext(NULL);

    InternationalPtr temp = realHead->i_getNext();
    delete *head;
    *head = temp;
    return 1;
}
