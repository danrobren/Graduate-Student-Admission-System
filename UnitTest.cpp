#include "UnitTest.hpp"
#include "FileReader.hpp"

void UnitTest::startTest()
{
    StudentBundle students = FileReader::readFile();

    DomesticPtr dHead = students.dList;
    InternationalPtr iHead = students.iList;
    int studentId = students.maxStudentID;

    insertTest(dHead, iHead, studentId);
    deleteTest(dHead, iHead);
    trimTest(dHead, iHead);
}

void UnitTest::insertTest(DomesticStudent* &dHead, InternationalStudent* &iHead, int &studentId)
{
    cout << endl << "====Insertion Testing=====" << endl;

    cout << "----Testing Domestic student list----" << endl;
    cout << R"(Insert Domestic Normal case: ("normal: ****first****", "****last****", 4.0, 80, studentId, "BC"))" << endl;
    DomesticStudent* dNormal = new DomesticStudent("normal: ****first****", "****last****", 4.0, 80, studentId, "BC");
    if(dNormal->insert(dHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << "Insert Domestic Edged case (head&tail):" << endl;
    cout << R"(inserting ("head: ****first****", "****last****", 2.0, 1, studentId, "BC"))" << endl;
    DomesticStudent* dEdgeHead = new DomesticStudent("head: ****first****", "****last****", 2.0, 1, studentId, "BC");
    if(dEdgeHead->insert(dHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << R"(inserting ("tail: ****first****", "****last****", 4.2, 100, studentId, "BC"))" << endl;
    DomesticStudent* dEdgeTail = new DomesticStudent("tail: ****first****", "****last****", 4.2, 100, studentId, "BC");
    if(dEdgeTail->insert(dHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << "Insert Domestic Illegal case (invalid province&cgpa):" << endl;
    cout << R"(inserting ("****first****", "****last****", 4.0, 80, studentId, "LMAO"))" << endl;
    DomesticStudent* dIlProvince = new DomesticStudent("****first****", "****last****", 4.0, 80, studentId, "LMAO");
    if(dIlProvince->insert(dHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }
    cout << endl << R"(inserting ("****first****", "****last****", -69, 80, studentId, "BC"))" << endl;
    DomesticStudent* dIlCgpa = new DomesticStudent("****first****", "****last****", -69, 80, studentId, "BC");
    if(dIlCgpa->insert(dHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << endl;
    d_printList(dHead);



    cout << endl << "----Testing International student list----" << endl;
    cout << R"(Insert International Normal case: ("normal: ****first****", "****last****", 4.0, 80, studentId, "China", (25,25,25,25)))" << endl;
    InternationalStudent* iNormal = new InternationalStudent("normal: ****first****", "****last****", 4.0, 80, studentId, "China", ToeflScore(25,25,25,25));
    if(iNormal->insert(iHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << "Insert International Edged case (head&tail):" << endl;
    cout << R"(inserting ("head: ****first****", "****last****", 2.0, 1, studentId, "China", (25,25,25,25)))" << endl;
    InternationalStudent* iEdgeHead = new InternationalStudent("head: ****first****", "****last****", 2.0, 1, studentId, "China", ToeflScore(25,25,25,25));
    if(iEdgeHead->insert(iHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << R"(inserting ("tail: ****first****", "****last****", 4.2, 100, studentId, "China", (25,25,25,25)))" << endl;
    InternationalStudent* iEdgeTail = new InternationalStudent("tail: ****first****", "****last****", 4.2, 100, studentId, "China", ToeflScore(25,25,25,25));
    if(iEdgeTail->insert(iHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << "Insert International Illegal case (invalid country/research score/toefl score):" << endl;
    cout << R"(inserting ("****first****", "****last****", 4.0, 80, studentId, "Wakanda", (25,25,25,25))" << endl;
    InternationalStudent* iIlCountry = new InternationalStudent("****first****", "****last****", 4.0, 80, studentId, "Wakanda", ToeflScore(25,25,25,25));
    if(iIlCountry->insert(iHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }
    cout << endl << R"(inserting ("****first****", "****last****", 4.0, 7777, studentId, "China", (25,25,25,25)))" << endl;
    InternationalStudent* iIlResearch = new InternationalStudent("****first****", "****last****", 4.0, 7777, studentId, "China", ToeflScore(25,25,25,25));
    if(iIlResearch->insert(iHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }
    cout << endl << R"(inserting ("****first****", "****last****", 4.0, 80, studentId, "China", (19,0,8,5)))" << endl;
    InternationalStudent* iIlLang = new InternationalStudent("****first****", "****last****", 4.0, 80, studentId, "China", ToeflScore(19,0,8,5));
    if(iIlLang->insert(iHead))
    {
        studentId++;
        cout << "inserted" << endl << endl;
    }

    cout << endl;
    i_printList(iHead);

}

void UnitTest::deleteTest(DomesticStudent *&dHead, InternationalStudent *&iHead)
{
    cout << endl << "====Deletion Testing=====" << endl;

    cout << "----Testing Domestic student list----" << endl;
    vector<DomesticStudent*> vd;
    cout << R"(deleting normal case: ("name: MiA coOk"))" << endl;
    vd = DomesticStudent::searchName("MiA", "coOk", dHead);
    if(vd.empty())
        cout << "noting deleted" << endl;
    for(DomesticStudent* &d : vd)
    {
        cout << "deleting " << *d << endl;
        d->deleteDomestic(dHead);
    }

    cout << R"(deleting normal case: ("research score: 77"))" << endl;
    vd = DomesticStudent::searchR(77, dHead);
    if(vd.empty())
        cout << "noting deleted" << endl;
    for(DomesticStudent* &d : vd)
    {
        cout << "deleting " << *d << endl;
        d->deleteDomestic(dHead);
    }

    cout << R"(deleting edged case: ("research score: 1"))" << endl;
    vd = DomesticStudent::searchR(1, dHead);
    if(vd.empty())
        cout << "noting deleted" << endl;
    for(DomesticStudent* &d : vd)
    {
        cout << "deleting " << *d << endl;
        d->deleteDomestic(dHead);
    }

    cout << R"(deleting illegal case: ("wrong name: meh meh"))" << endl;
    vd = DomesticStudent::searchName("meh", "meh", dHead);
    if(vd.empty())
        cout << "noting deleted" << endl;
    for(DomesticStudent* &d : vd)
    {
        cout << "deleting " << *d << endl;
        d->deleteDomestic(dHead);
    }

    cout << R"(deleting illegal case: ("invalid cgpa: -5"))" << endl;
    vd = DomesticStudent::searchC(-5, dHead);
    if(vd.empty())
        cout << "noting deleted" << endl;
    for(DomesticStudent* &d : vd)
    {
        cout << "deleting " << *d << endl;
        d->deleteDomestic(dHead);
    }

    cout << endl;
    d_printList(dHead);

    cout << "----Testing International student list----" << endl;
    vector<InternationalStudent*> vi;
    cout << R"(deleting normal case: ("name: XIaOyiNg wU"))" << endl;
    vi = InternationalStudent::searchName("XIaOyiNg", "wU", iHead);
    if(vi.empty())
        cout << "noting deleted" << endl;
    for(InternationalStudent* &i : vi)
    {
        cout << "deleting " << *i << endl;
        i->deleteInternational(iHead);
    }

    cout << R"(deleting normal case: ("Research Score: 88"))" << endl;
    vi = InternationalStudent::searchR(88, iHead);
    if(vi.empty())
        cout << "noting deleted" << endl;
    for(InternationalStudent* &i : vi)
    {
        cout << "deleting " << *i << endl;
        i->deleteInternational(iHead);
    }

    cout << R"(deleting edged case: ("head: Research Score: 1"))" << endl;
    vi = InternationalStudent::searchR(1, iHead);
    if(vi.empty())
        cout << "noting deleted" << endl;
    for(InternationalStudent* &i : vi)
    {
        cout << "deleting " << *i << endl;
        i->deleteInternational(iHead);
    }

    cout << R"(deleting illegal case: ("wrong name: meh meh"))" << endl;
    vi = InternationalStudent::searchName("meh", "meh", iHead);
    if(vi.empty())
        cout << "noting deleted" << endl;
    for(InternationalStudent* &i : vi)
    {
        cout << "deleting " << *i << endl;
        i->deleteInternational(iHead);
    }

    cout << R"(deleting illegal case: ("invalid cgpa: -5"))" << endl;
    vi = InternationalStudent::searchC(-5, iHead);
    if(vi.empty())
        cout << "noting deleted" << endl;
    for(InternationalStudent* &i : vi)
    {
        cout << "deleting " << *i << endl;
        i->deleteInternational(iHead);
    }

    cout << endl;
    i_printList(iHead);
}

void UnitTest::trimTest(DomesticStudent* &dHead, InternationalStudent* &iHead)
{
    cout << endl << "====Trim Testing=====" << endl;
    if(d_trimHeadTail(&dHead))
    {
        cout << "Domestic Head and Tail removed" << endl;
        d_printList(dHead);
    }
    if(i_trimHeadTail(&iHead))
    {
        cout << "International Head and Tail removed" << endl;
        i_printList(iHead);
    }
}
