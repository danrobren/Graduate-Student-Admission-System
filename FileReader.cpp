#include "FileReader.hpp"
#include "error.hpp"

StudentBundle FileReader::readFile()
{
    //vector<DomesticStudent> domestic;
    //vector<InternationalStudent> international;

    DomesticPtr dHead = nullptr;
    DomesticPtr dTail = nullptr;
    InternationalPtr iHead = nullptr;
    InternationalPtr iTail = nullptr;

    int student_id = 20220000;

    string line;
    ifstream domesticFile("domestic-stu.txt");
    ifstream internationalFile("international-stu.txt");

    if (!domesticFile.is_open() || !internationalFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt or international-stu.txt" << endl;
        return {};
    }

    cout << "====File parsing start====" << endl;
    getline(domesticFile, line);
    cout << "File domestic-stu.txt format: " << line << endl;
    getline(internationalFile, line);
    cout << "File international-stu.txt format: " << line << endl;
    while (getline(domesticFile, line))
    {
        istringstream ss(line);
        string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;

        //get firstName separated by comma
        if(!getline(ss, firstName, ',')) cout << "First name field not read correctly";

        //get lastName separated by comma
        if(!getline(ss, lastName, ',')) cout << "Last name field not read correctly";

        //get province separated by comma
        if(!getline(ss, province, ',')) cout << "Province field not read correctly";

        //get cpga separated by comma, and convert string to float
        if(!getline(ss, s_cgpa, ',')) cout << "CGPA field not read correctly";
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        if(!getline(ss, s_researchScore, ',')) cout << "Research score field not read correctly";
        researchScore = atoi(s_researchScore.c_str());

        //domestic.emplace_back(firstName, lastName, cgpa, researchScore, student_id, province);

        DomesticPtr n_domestic = new DomesticStudent( firstName, lastName, cgpa, researchScore, student_id, province );

        if(!dHead)
        {
            dHead = n_domestic;
        }
        else
        {
            n_domestic->insert(dHead);
        }
        student_id++;
    }

    while (getline(internationalFile, line)) {
        istringstream ss(line);

        string firstName, lastName, country, s_cgpa, s_researchScore, s_Reading, s_Listening, s_Speaking, s_Writing;
        float cgpa;
        int researchScore, Reading, Listening, Speaking, Writing;

        //get firstName separated by comma
        if(!getline(ss, firstName, ',')) cout << "First name field missing or not read correctly";

        //get lastName separated by comma
        if(!getline(ss, lastName, ',')) cout << "Last name field missing or not read correctly";

        //get province separated by comma
        if(!getline(ss, country, ',')) cout << "Country name field missing or not read correctly";

        //get cpga separated by comma, and convert string to float
        if(!getline(ss, s_cgpa, ',')) cout << "CGPA name field missing or not read correctly";
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        if(!getline(ss, s_researchScore, ',')) cout << "Research score name field missing or not read correctly";
        researchScore = atoi(s_researchScore.c_str());

        //get Reading separated by comma
        if(!getline(ss, s_Reading, ',')) cout << "TOEFL reading field missing or not read correctly";
        Reading = atoi(s_Reading.c_str());

        //get Listening separated by comma
        if(!getline(ss, s_Listening, ',')) cout << "TOEFL listening field missing or not read correctly";
        Listening = atoi(s_Listening.c_str());

        //get Speaking separated by comma
        if(!getline(ss, s_Speaking, ',')) cout << "TOEFL speaking field missing or not read correctly";
        Speaking = atoi(s_Speaking.c_str());

        //get Writing separated by comma
        if(!getline(ss, s_Writing, ',')) cout << "TOEFL writing field missing or not read correctly";
        Writing = atoi(s_Writing.c_str());

        //international.emplace_back(firstName, lastName, cgpa, researchScore, student_id, country, ToeflScore(Reading, Writing, Listening, Speaking));

        InternationalPtr n_international = new InternationalStudent( firstName, lastName, cgpa, researchScore, student_id, country, ToeflScore(Reading, Writing, Listening, Speaking) );

        if(!iHead)
        {
            iHead = n_international;
        }
        else
        {
            n_international->insert(iHead);
        }

        student_id++;
    }

    domesticFile.close();
    internationalFile.close();

    cout << "====File parsing finished====" << endl;

    StudentBundle students{};
    students.dList = dHead;
    students.dTail = d_findTail(dHead);
    students.iList = iHead;
    students.iTail = i_findTail(iHead);
    students.maxStudentID = student_id;
    return students;
}
