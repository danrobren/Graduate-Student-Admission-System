#include "UserIO.hpp"
#include "merge.hpp"
#include "FileReader.hpp"
#include "filter.hpp"

void UserIO::inputStudent(DomesticStudent* &dHead, InternationalStudent* &iHead, int &studentId)
{
    bool cont = true;
    while(cont)
    {
        cout << "Select a type of student: " << endl;
        cout << "[0] Domestic Student" << endl;
        cout << "[1] International Student" << endl;
        cout << "[2] Cancel" << endl;
        int stuType = askForInt(cin, cout);

        if(stuType == 0)
        {
            string firstNameText = "[0] First Name";
            string lastNameText = "[1] last Name";
            string cgpaText = "[2] CGPA";
            string researchText = "[3] Research Score";
            string provinceText = "[4] Province";

            string firstName;
            string lastName;
            float cgpa;
            int researchScore;
            string province;

            bool cancelled = false;
            bool firstNameFilled = false;
            bool lastNameFilled = false;
            bool cgpaFilled = false;
            bool researchFilled = false;
            bool provinceFilled = false;
            bool isFilled = false;
            while(!isFilled && !cancelled)
            {
                cout << "fill in the information: " << endl;
                cout << firstNameText << endl;
                cout << lastNameText << endl;
                cout << cgpaText << endl;
                cout << researchText << endl;
                cout << provinceText << endl;
                cout << "[5] Cancel" << endl;
                int in = askForInt(cin, cout);

                switch(in)
                {
                    case 0:
                    {
                        cout << "input/re-input first name: " << endl;
                        cin >> firstName;
                        firstNameFilled = true;
                        firstNameText += (" (" + firstName + ")");
                        break;
                    }
                    case 1:
                    {
                        cout << "input/re-input last name: " << endl;
                        cin >> lastName;
                        lastNameFilled = true;
                        lastNameText += (" (" + lastName + ")");
                        break;
                    }
                    case 2:
                    {
                        cout << "input/re-input CGPA: " << endl;
                        cgpa = askForFloat(cin, cout);
                        cgpaFilled = true;
                        cgpaText += (" (" + to_string(cgpa).substr(0,4) + ")");
                        break;
                    }
                    case 3:
                    {
                        cout << "input/re-input research score: " << endl;
                        researchScore = askForInt(cin, cout);
                        researchFilled = true;
                        researchText += (" (" + to_string(researchScore) + ")");
                        break;
                    }
                    case 4:
                    {
                        cout << "input/re-input province: " << endl;
                        cin >> province;
                        provinceFilled = true;
                        provinceText += (" (" + province + ")");
                        break;
                    }
                    case 5:
                    {
                        cancelled = true;
                        cont = false;
                        break;
                    }
                    default:
                    {
                        cout << "please input a valid number 0~5" << endl;
                    }
                }

                isFilled = firstNameFilled && lastNameFilled && cgpaFilled && researchFilled && provinceFilled;
            }

            if(isFilled && !cancelled)
            {
                DomesticStudent* insertItem = new DomesticStudent(firstName, lastName, cgpa, researchScore, studentId, province);
                if(insertItem->insert(dHead))
                {
                    studentId++;
                    cout << "inserted" << endl;
                }
                cont = false;
            }
        }
        else if(stuType == 1)
        {
            string firstNameText = "[0] First Name";
            string lastNameText = "[1] last Name";
            string cgpaText = "[2] CGPA";
            string researchText = "[3] Research Score";
            string countryText = "[4] Country";
            string toeflText = "[5] Toefl Score";

            string firstName;
            string lastName;
            float cgpa;
            int researchScore;
            string country;
            ToeflScore toeflScore;

            bool cancelled = false;
            bool firstNameFilled = false;
            bool lastNameFilled = false;
            bool cgpaFilled = false;
            bool researchFilled = false;
            bool countryFilled = false;
            bool toeflFilled = false;
            bool isFilled = false;
            while(!isFilled && !cancelled)
            {

                cout << "fill in the information: " << endl;
                cout << firstNameText << endl;
                cout << lastNameText << endl;
                cout << cgpaText << endl;
                cout << researchText << endl;
                cout << countryText << endl;
                cout << toeflText << endl;
                cout << "[6] Cancel" << endl;
                int in = askForInt(cin, cout);

                switch(in)
                {
                    case 0:
                    {
                        cout << "input/re-input first name: " << endl;
                        cin >> firstName;
                        firstNameFilled = true;
                        firstNameText += (" (" + firstName + ")");
                        break;
                    }
                    case 1:
                    {
                        cout << "input/re-input last name: " << endl;
                        cin >> lastName;
                        lastNameFilled = true;
                        lastNameText += (" (" + lastName + ")");
                        break;
                    }
                    case 2:
                    {
                        cout << "input/re-input CGPA: " << endl;
                        cgpa = askForFloat(cin, cout);
                        cgpaFilled = true;
                        cgpaText += (" (" + to_string(cgpa).substr(0,4) + ")");
                        break;
                    }
                    case 3:
                    {
                        cout << "input/re-input research score: " << endl;
                        researchScore = askForInt(cin, cout);
                        researchFilled = true;
                        researchText += (" (" + to_string(researchScore) + ")");
                        break;
                    }
                    case 4:
                    {
                        cout << "input/re-input country: " << endl;
                        cin >> country;
                        countryFilled = true;
                        countryText += (" (" + country + ")");
                        break;
                    }
                    case 5:
                    {
                        int reading, writing, listening, speaking;
                        cout << "input/re-input toefl score[reading writing listening speaking]: " << endl;
                        reading = askForInt(cin, cout);
                        writing = askForInt(cin, cout);
                        listening = askForInt(cin, cout);
                        speaking = askForInt(cin, cout);
                        //cin >> reading >> writing >> listening >> speaking;
                        toeflScore = ToeflScore(reading, writing, listening, speaking);
                        toeflFilled = true;
                        toeflText += (" (" + to_string(reading) + "/" + to_string(writing) + "/" + to_string(listening) + "/" + to_string(speaking) + "/total: " + to_string(toeflScore.getTotal()) + +")");
                        break;
                    }
                    case 6:
                    {
                        cancelled = true;
                        cont = false;
                        break;
                    }
                    default:
                    {
                        cout << "please input a valid number 0~6" << endl;
                    }
                }

                isFilled = firstNameFilled && lastNameFilled && cgpaFilled && researchFilled && countryFilled && toeflFilled;
            }

            if(isFilled && !cancelled)
            {
                InternationalStudent* insertItem = new InternationalStudent(firstName, lastName, cgpa, researchScore, studentId, country, toeflScore);
                if(insertItem->insert(iHead))
                {
                    studentId++;
                    cout << "inserted" << endl;
                }
                cont = false;
            }
        }
        else if(stuType == 2)
        {
            cont = false;
        }
        else
        {
            cout << "please input number 0~2: " << endl;
        }
    }

}

void UserIO::deleteStudent(DomesticStudent* &dHead, InternationalStudent* &iHead)
{
    bool cont = true;
    while(cont)
    {
        cout << "Select a type of student to delete: " << endl;
        cout << "[0] Domestic Student" << endl;
        cout << "[1] International Student" << endl;
        cout << "[2] Cancel" << endl;
        int stuType = askForInt(cin, cout);

        if(stuType == 0)
        {
            bool cont_delete = true;
            while(cont_delete)
            {
                cout << "delete by: " << endl;
                cout << "[0] ID" << endl;
                cout << "[1] Name" << endl;
                cout << "[2] CGPA" << endl;
                cout << "[3] Research Score" << endl;
                cout << "[4] Return" << endl;
                int in = askForInt(cin, cout);

                switch(in)
                {
                    case 0:
                    {

                        cout << "input application id: " << endl;
                        int id = askForInt(cin, cout);

                        vector<DomesticStudent*> v = DomesticStudent::searchA(id, dHead);
                        for(DomesticStudent* d : v)
                        {
                            d->deleteDomestic(dHead);
                        }
                        cout << "done" << endl;
                        cont_delete = false;
                        cont = false;
                        break;
                    }
                    case 1:
                    {
                        string firstName;
                        string lastName;
                        cout << "input name: " << endl;
                        cin >> firstName;
                        cin >> lastName;
                        vector<DomesticStudent*> v = DomesticStudent::searchName(firstName, lastName, dHead);
                        for(DomesticStudent* d : v)
                        {
                            d->deleteDomestic(dHead);
                        }
                        cont_delete = false;
                        cont = false;
                        break;
                    }
                    case 2:
                    {

                        cout << "input cgpa: " << endl;
                        float cgpa = askForFloat(cin, cout);

                        vector<DomesticStudent*> v = DomesticStudent::searchC(cgpa, dHead);
                        for(DomesticStudent* d : v)
                        {
                            d->deleteDomestic(dHead);
                        }
                        cout << "done" << endl;
                        cont_delete = false;
                        cont = false;
                        break;
                    }
                    case 3:
                    {
                        cout << "input research score: " << endl;
                        int researchScore = askForInt(cin, cout);

                        vector<DomesticStudent*> v = DomesticStudent::searchR(researchScore, dHead);
                        for(DomesticStudent* d : v)
                        {
                            d->deleteDomestic(dHead);
                        }
                        cout << "done" << endl;
                        cont_delete = false;
                        cont = false;
                        break;
                    }
                    case 4:
                    {
                        cont_delete = false;
                        break;
                    }
                    default:
                    {
                        cout << "please input a valid number 0~4" << endl;
                    }
                }
            }
        }
        else if(stuType == 1)
        {
            bool cont_delete = true;
            while(cont_delete)
            {
                cout << "delete by: " << endl;
                cout << "[0] ID" << endl;
                cout << "[1] Name" << endl;
                cout << "[2] CGPA" << endl;
                cout << "[3] Research Score" << endl;
                cout << "[4] Return" << endl;
                int in = askForInt(cin, cout);

                switch(in)
                {
                    case 0:
                    {
                        cout << "input application id: " << endl;
                        int id = askForInt(cin, cout);

                        vector<InternationalStudent*> v = InternationalStudent::searchA(id, iHead);
                        for(InternationalStudent* i : v)
                        {
                            i->deleteInternational(iHead);
                        }
                        cout << "done" << endl;
                        cont_delete = false;
                        cont = false;
                        break;
                    }
                    case 1:
                    {
                        string firstName;
                        string lastName;
                        cout << "input name: " << endl;
                        cin >> firstName;
                        cin >> lastName;
                        vector<InternationalStudent*> v = InternationalStudent::searchName(firstName, lastName, iHead);
                        for(InternationalStudent* i : v)
                        {
                            i->deleteInternational(iHead);
                        }
                        cout << "done" << endl;
                        cont = false;
                        cont_delete = false;
                        break;
                    }
                    case 2:
                    {
                        cout << "input cgpa: " << endl;
                        float cgpa= askForFloat(cin, cout);

                        vector<InternationalStudent*> v = InternationalStudent::searchC(cgpa, iHead);
                        for(InternationalStudent* i : v)
                        {
                            i->deleteInternational(iHead);
                        }
                        cout << "done" << endl;
                        cont = false;
                        cont_delete = false;
                        break;
                    }
                    case 3:
                    {
                        cout << "input research score: " << endl;
                        int researchScore = askForInt(cin, cout);

                        vector<InternationalStudent*> v = InternationalStudent::searchR(researchScore, iHead);
                        for(InternationalStudent* i : v)
                        {
                            i->deleteInternational(iHead);
                        }
                        cout << "done" << endl;
                        cont = false;
                        cont_delete = false;
                        break;
                    }
                    case 4:
                    {
                        cont_delete = false;
                        break;
                    }
                    default:
                    {
                        cout << "please input a valid number 0~4" << endl;
                    }
                }
            }
        }
        else if(stuType == 2)
        {
            cont = false;
        }
        else
        {
            cout << "please input number 0~2: " << endl;
        }
    }

}

void UserIO::searchStudent(DomesticStudent* &dHead, InternationalStudent* &iHead)
{
    bool cont = true;
    while(cont)
    {

        cout << "Select a type of student to search: " << endl;
        cout << "[0] Domestic Student" << endl;
        cout << "[1] International Student" << endl;
        cout << "[2] Search in Merged list" << endl;
        cout << "[3] Cancel" << endl;
        int stuType = askForInt(cin, cout);

        if(stuType == 0)
        {
            bool cont_search = true;
            while(cont_search)
            {
                cout << "search by: " << endl;
                cout << "[0] ID" << endl;
                cout << "[1] Name" << endl;
                cout << "[2] CGPA" << endl;
                cout << "[3] Research Score" << endl;
                cout << "[4] Return" << endl;
                int in = askForInt(cin, cout);

                switch(in)
                {
                    case 0:
                    {

                        cout << "input application id: " << endl;
                        int id = askForInt(cin, cout);

                        vector<DomesticStudent*> v = DomesticStudent::searchA(id, dHead);
                        for(DomesticStudent* d : v)
                        {
                            cout << *d << endl;
                        }
                        break;
                    }
                    case 1:
                    {
                        string firstName;
                        string lastName;
                        cout << "input name: " << endl;
                        cin >> firstName;
                        cin >> lastName;
                        vector<DomesticStudent*> v = DomesticStudent::searchName(firstName, lastName, dHead);
                        for(DomesticStudent* d : v)
                        {
                            cout << *d << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "input cgpa: " << endl;
                        float cgpa = askForFloat(cin, cout);

                        vector<DomesticStudent*> v = DomesticStudent::searchC(cgpa, dHead);
                        for(DomesticStudent* d : v)
                        {
                            cout << *d << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "input research score: " << endl;
                        int researchScore = askForInt(cin, cout);

                        vector<DomesticStudent*> v = DomesticStudent::searchR(researchScore, dHead);
                        for(DomesticStudent* d : v)
                        {
                            cout << *d << endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cont_search = false;
                        break;
                    }
                    default:
                    {
                        cout << "please input a valid number 0~4" << endl;
                    }
                }
            }
        }
        else if(stuType == 1)
        {
            bool cont_search = true;
            while(cont_search)
            {
                cout << "search by: " << endl;
                cout << "[0] ID" << endl;
                cout << "[1] Name" << endl;
                cout << "[2] CGPA" << endl;
                cout << "[3] Research Score" << endl;
                cout << "[4] Return" << endl;
                int in = askForInt(cin, cout);

                switch(in)
                {
                    case 0:
                    {
                        cout << "input application id: " << endl;
                        int id = askForInt(cin, cout);

                        vector<InternationalStudent*> v = InternationalStudent::searchA(id, iHead);
                        for(InternationalStudent* i : v)
                        {
                            cout << *i << endl;
                        }
                        break;
                    }
                    case 1:
                    {
                        string firstName;
                        string lastName;
                        cout << "input name: " << endl;
                        cin >> firstName;
                        cin >> lastName;
                        vector<InternationalStudent*> v = InternationalStudent::searchName(firstName, lastName, iHead);
                        for(InternationalStudent* i : v)
                        {
                            cout << *i << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "input cgpa: " << endl;
                        float cgpa = askForFloat(cin, cout);

                        vector<InternationalStudent*> v = InternationalStudent::searchC(cgpa, iHead);
                        for(InternationalStudent* i : v)
                        {
                            cout << *i << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "input research score: " << endl;
                        int researchScore = askForInt(cin, cout);

                        vector<InternationalStudent*> v = InternationalStudent::searchR(researchScore, iHead);
                        for(InternationalStudent* i : v)
                        {
                            cout << *i << endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cont_search = false;
                        break;
                    }
                    default:
                    {
                        cout << "please input a valid number 0~4" << endl;
                    }
                }
            }
        }
        else if(stuType == 2)
        {
            Student* mergedHead = Merge::mergeLists(dHead, iHead);
            bool cont_search = true;
            while(cont_search)
            {
                cout << "search by: " << endl;
                cout << "[0] ID" << endl;
                cout << "[1] Name" << endl;
                cout << "[2] CGPA" << endl;
                cout << "[3] Research Score" << endl;
                cout << "[4] Return" << endl;
                int in = askForInt(cin, cout);

                switch(in)
                {
                    case 0:
                    {
                        cout << "input application id: " << endl;
                        int id = askForInt(cin, cout);

                        vector<Student*> v = Student::searchA(id, mergedHead);
                        for(Student* s : v)
                        {
                            cout << *s << endl;
                        }
                        break;
                    }
                    case 1:
                    {
                        string firstName;
                        string lastName;
                        cout << "input name: " << endl;
                        cin >> firstName;
                        cin >> lastName;
                        vector<Student*> v = Student::searchName(firstName, lastName, mergedHead);
                        for(Student* s : v)
                        {
                            cout << *s << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "input cgpa: " << endl;
                        float cgpa = askForFloat(cin, cout);

                        vector<Student*> v = Student::searchC(cgpa, mergedHead);
                        for(Student* s : v)
                        {
                            cout << *s << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "input research score: " << endl;
                        int researchScore = askForInt(cin, cout);

                        vector<Student*> v = Student::searchR(researchScore, mergedHead);
                        for(Student* s : v)
                        {
                            cout << *s << endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cont_search = false;
                        break;
                    }
                    default:
                    {
                        cout << "please input a valid number 0~4" << endl;
                    }
                }
            }
        }
        else if(stuType == 3)
        {
            cont = false;
        }
        else
        {
            cout << "please input number 0~2: " << endl;
        }
    }

}

void UserIO::printAllStudent(DomesticStudent* &dHead, InternationalStudent* &iHead)
{
    bool cont = true;
    while(cont)
    {

        cout << "Select a type of student to print: " << endl;
        cout << "[0] Domestic Student" << endl;
        cout << "[1] International Student" << endl;
        cout << "[2] Merged Student" << endl;
        cout << "[3] Cancel" << endl;
        int stuType = askForInt(cin, cout);

        if(stuType == 0)
        {
            DomesticStudent* current = dHead;
            while(current != nullptr)
            {
                cout << *current << endl;
                current = current->d_getNext();
                cont = false;
            }
        }
        else if(stuType == 1)
        {
            InternationalStudent* current = iHead;
            while(current != nullptr)
            {
                cout << *current << endl;
                current = current->i_getNext();
                cont = false;
            }
        }
        else if(stuType == 2)
        {
            Student* s = Merge::mergeLists(dHead, iHead);
            Student* current = s;
            while(current != nullptr)
            {
                cout << *current << endl;
                current = current->getNext();
                cont = false;
            }
        }
        else if(stuType == 3)
        {
            cont = false;
        }
        else
        {
            cout << "please input number 0~3: " << endl;
        }
    }
}

void UserIO::startApplication()
{
    StudentBundle students = FileReader::readFile();

    DomesticPtr dhead = students.dList;
    InternationalPtr ihead = students.iList;
    int studentId = students.maxStudentID;

    cout << "====Graduate Student Admission System====" << endl;
    bool cont = true;
    int in;
    while(cont)
    {
        cout << "[0] Input a student" << endl;
        cout << "[1] Delete a student/students" << endl;
        cout << "[2] Search for students" << endl;
        cout << "[3] Print all" << endl;
        cout << "[4] Disciplinary Record System" << endl;
        cout << "[5] Filter students" <<endl;
        cout << "[6] Exit" << endl;
        cout << "input your command[0~6]: " << endl;
        in = askForInt(cin, cout);

        if(in == 0)
        {
            inputStudent(dhead, ihead, studentId);
        }
        else if(in == 1)
        {
            deleteStudent(dhead, ihead);
        }
        else if(in == 2)
        {
            searchStudent(dhead, ihead);
        }
        else if(in == 3)
        {
            printAllStudent(dhead, ihead);
        }
        else if(in == 4)
        {
            UserIO::disciplinarySystem(dhead, ihead);
        }
        else if( in == 5)
        {
            UserIO::filterStudent(dhead, ihead);
        }
        else if(in == 6)
        {
            cout << "Thanks for using!" << endl;
            cont = false;
        }
        else
        {
            cout << "please input a valid command" << endl;
        }
    }
}

void UserIO::disciplinarySystem(DomesticStudent *&dHead, InternationalStudent *&iHead)
{
    bool cont = true;
    while(cont)
    {
        cout << "[0] Add disciplinary strike" << endl;
        cout << "[1] Disciplinary record inquiry" << endl;
        cout << "[2] return" << endl;
        int in = askForInt(cin, cout);
        if(in == 0)
        {
            StudentPtr head = Merge::mergeLists(dHead, iHead);
            addStrike( head );
        }
        else if(in == 1)
        {
            StudentPtr head = Merge::mergeLists(dHead, iHead);
            disciplinaryInquiry( head );
        }
        else if(in == 2)
        {
            cont = false;
        }
        else
        {
            cout << "please input number 0~2: " << endl;
        }
    }
}

void UserIO::filterStudent(DomesticStudent *&dHead, InternationalStudent *&iHead)
{
    bool cont = true;
    while(cont)
    {

        cout << "Select a type of student to filter: " << endl;
        cout << "[0] Domestic Student" << endl;
        cout << "[1] International Student" << endl;
        cout << "[2] Merged list" << endl;
        cout << "[3] Cancel" << endl;
        int stuType = askForInt(cin, cout);

        if(stuType == 0)
        {
            filter(0, dHead, iHead);
        }
        else if(stuType == 1)
        {
            filter(1, dHead, iHead);
        }
        else if(stuType == 2)
        {
            filter(2, dHead, iHead);
        }
        else if(stuType == 3)
        {
            cont = false;
        }
        else
        {
            cout << "please input number 0~2: " << endl;
        }
    }
}

int UserIO::askForInt(istream &i, ostream &o)
{
    int in;
    while(!(i >> in))
    {
        i.clear();
        i.ignore(INT_MAX, '\n');
        o << "Invalid input type, please input an INTEGER: " << endl;
    }
    return in;
}

float UserIO::askForFloat(istream &i, ostream &o)
{
    float in;
    while(!(i >> in))
    {
        i.clear();
        i.ignore(INT_MAX, '\n');
        o << "Invalid input type, please input an FLOAT: " << endl;
    }
    return in;
}

void UserIO::filter(const int &type, DomesticStudent *&dHead, InternationalStudent *&iHead)
{
    string cgpaText = "[0] CGPA";
    string rsText = "[1] Research Score";

    bool cgpaConditioned = false;
    int cgpaCondition;
    vector<float> cgpaVal(2);


    bool rsConditioned = false;
    int rsCondition;
    vector<int> rsVal(2);

    bool cont_filter = true;
    while(cont_filter)
    {
        cout << "filter by: " << endl;
        cout << cgpaText << endl;
        cout << rsText << endl;
        cout << "[2] Filter" << endl;
        cout << "[3] Return" << endl;
        int in = askForInt(cin, cout);

        switch(in)
        {
            case 0:
            {
                cout << "select condition:" << endl;
                cout << "[0] >" << endl;
                cout << "[1] >=" << endl;
                cout << "[2] <" << endl;
                cout << "[3] <=" << endl;
                cout << "[4] between" << endl;
                cout << "[else] return" << endl;
                int condition = askForInt(cin, cout);
                switch(condition)
                {
                    case 0:
                    {
                        cout << "enter a float: " << endl;
                        cgpaCondition = 0;
                        cgpaVal[0] = askForFloat(cin, cout);
                        cgpaConditioned = true;
                        cgpaText = "[0] CGPA (>" + to_string(cgpaVal[0]).substr(0,4) + ")";
                        break;
                    }
                    case 1:
                    {
                        cout << "enter a float: " << endl;
                        cgpaCondition = 1;
                        cgpaVal[0] = askForFloat(cin, cout);
                        cgpaConditioned = true;
                        cgpaText = "[0] CGPA (>=" + to_string(cgpaVal[0]).substr(0,4) + ")";
                        break;
                    }
                    case 2:
                    {
                        cout << "enter a float: " << endl;
                        cgpaCondition = 2;
                        cgpaVal[0] = askForFloat(cin, cout);
                        cgpaConditioned = true;
                        cgpaText = "[0] CGPA (<" + to_string(cgpaVal[0]).substr(0,4) + ")";
                        break;
                    }
                    case 3:
                    {
                        cout << "enter a float: " << endl;
                        cgpaCondition = 3;
                        cgpaVal[0] = askForFloat(cin, cout);
                        cgpaConditioned = true;
                        cgpaText = "[0] CGPA (<=" + to_string(cgpaVal[0]).substr(0,4) + ")";
                        break;
                    }
                    case 4:
                    {
                        cout << "enter two floats [from to]: " << endl;
                        cgpaCondition = 4;
                        cgpaVal[0] = askForFloat(cin, cout);
                        cgpaVal[1] = askForFloat(cin, cout);
                        cgpaConditioned = true;
                        cgpaText = "[0] CGPA (>=" + to_string(cgpaVal[0]).substr(0,4) + " and <= " + to_string(cgpaVal[1]).substr(0,4) + ")";
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 1:
            {
                cout << "select condition:" << endl;
                cout << "[0] >" << endl;
                cout << "[1] >=" << endl;
                cout << "[2] <" << endl;
                cout << "[3] <=" << endl;
                cout << "[4] between" << endl;
                cout << "[else] return" << endl;
                int condition = askForInt(cin, cout);
                switch(condition)
                {
                    case 0:
                    {
                        cout << "enter an int: " << endl;
                        rsCondition = 0;
                        rsVal[0] = askForInt(cin, cout);
                        rsConditioned = true;
                        rsText = "[1] Research Score (>" + to_string(rsVal[0]) + ")";
                        break;
                    }
                    case 1:
                    {
                        cout << "enter an int: " << endl;
                        rsCondition = 1;
                        rsVal[0] = askForInt(cin, cout);
                        rsConditioned = true;
                        rsText = "[1] Research Score (>=" + to_string(rsVal[0]) + ")";
                        break;
                    }
                    case 2:
                    {
                        cout << "enter an int: " << endl;
                        rsCondition = 2;
                        rsVal[0] = askForInt(cin, cout);
                        rsConditioned = true;
                        rsText = "[1] Research Score (<" + to_string(rsVal[0]) + ")";
                        break;
                    }
                    case 3:
                    {
                        cout << "enter an int: " << endl;
                        rsCondition = 3;
                        rsVal[0] = askForInt(cin, cout);
                        rsConditioned = true;
                        rsText = "[1] Research Score (<=" + to_string(rsVal[0]) + ")";
                        break;
                    }
                    case 4:
                    {
                        cout << "enter two ints [from to]: " << endl;
                        rsCondition = 4;
                        rsVal[0] = askForInt(cin, cout);
                        rsVal[1] = askForInt(cin, cout);
                        rsConditioned = true;
                        rsText = "[1] Research Score (>=" + to_string(rsVal[0]) + " and <= " + to_string(rsVal[1]) + ")";
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                if(!cgpaConditioned && !rsConditioned)
                {
                    cout << "please input conditions" << endl;
                    break;
                }
                Conditions c(cgpaConditioned, cgpaCondition, cgpaVal, rsConditioned, rsCondition, rsVal);
                if(type == 0)
                {
                    vector<DomesticStudent*> v = filter::getFilterResult(dHead, c);
                    if(v.empty())
                    {
                        cout << "no matched found, no operation can be done" << endl;
                        cont_filter = false;
                        break;
                    }
                    else
                    {
                        cout << "[0] print" << endl;
                        cout << "[1] delete" << endl;
                        cout << "[else] return" << endl;
                        int op = askForInt(cin, cout);
                        if(op == 0)
                        {
                            for(DomesticStudent* i : v)
                                cout << *i << endl;
                        }
                        else if(op == 1)
                        {
                            for(DomesticStudent* i : v)
                                i->deleteDomestic(dHead);
                        }
                        cont_filter = false;
                        break;
                    }
                }
                else if(type == 1)
                {
                    vector<InternationalStudent*> v = filter::getFilterResult(iHead, c);
                    if(v.empty())
                    {
                        cout << "no matched found, no operation can be done" << endl;
                        cont_filter = false;
                        break;
                    }
                    else
                    {
                        cout << "[0] print" << endl;
                        cout << "[1] delete" << endl;
                        cout << "[else] return" << endl;
                        int op = askForInt(cin, cout);
                        if(op == 0)
                        {
                            for(InternationalStudent* i : v)
                                cout << *i << endl;
                        }
                        else if(op == 1)
                        {
                            for(InternationalStudent* i : v)
                                i->deleteInternational(iHead);
                        }
                        cont_filter = false;
                        break;
                    }
                }
                else
                {
                    vector<Student*> v = filter::getFilterResult(Merge::mergeLists(dHead, iHead), c);
                    if(v.empty())
                    {
                        cout << "no matched found, no operation can be done" << endl;
                        cont_filter = false;
                        break;

                    }
                    else
                    {
                        for(Student* i : v)
                            cout << *i << endl;
                        cont_filter = false;
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                cont_filter = false;
                break;
            }
            default:
            {
                cout << "please input a valid number 0~4" << endl;
                break;
            }
        }
    }
}

Conditions::Conditions(const bool &cgpaConditionedIn, const int &cgpaConditionIn, const vector<float> &cgpaValIn,
                       const bool &rsConditionedIn, const int &rsConditionIn, const vector<int> &rsValIn)
{
    cgpaConditioned = cgpaConditionedIn;
    cgpaCondition = cgpaConditionIn;
    cgpaVal = cgpaValIn;

    rsConditioned = rsConditionedIn;
    rsCondition = rsConditionIn;
    rsVal = rsValIn;
}
