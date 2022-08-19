#include "filter.hpp"
//"[0] >"
//"[1] >="
//"[2] <"
//"[3] <="
//"[4] between"
vector<DomesticStudent *> filter::getFilterResult(DomesticStudent *dHead, Conditions &c)
{
    if (dHead == nullptr)
    {
        //case list is empty
        cout << "List is Empty" << endl;
        return {};
    }

    //case list has atleast one object
    vector<DomesticStudent*> v;

    if(c.cgpaConditioned && !c.rsConditioned)
    {
        DomesticPtr curr = dHead;
        if (c.cgpaVal[0] < 0 || c.cgpaVal[0] > 4.33)
        {
            cout << "invalid cgpa" << endl;
            return {};
        }
        switch(c.cgpaCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() > c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() < c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() <= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 4:
            {
                if (c.cgpaVal[1] < 0 || c.cgpaVal[1] > 4.33) {
                    cout << "invalid cgpa" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0] && curr->get_cgpa() <= c.cgpaVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            default:
            {
                return {};
            }
        }
    }
    if(!c.cgpaConditioned && c.rsConditioned)
    {
        DomesticPtr curr = dHead;
        if (c.rsVal[0] < 0 || c.rsVal[0]>100) {
            cout << "invalid research score" << endl;
            return {};
        }
        switch(c.rsCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() > c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() >= c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() < c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() <= c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 4:
            {
                if (c.rsVal[1] < 0 || c.rsVal[1]>100) {
                    cout << "invalid research score" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->getResearchScore()>= c.rsVal[0] && curr->getResearchScore() <= c.rsVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            default:
            {
                return {};
            }
        }
    }
    if(c.cgpaConditioned && c.rsConditioned)
    {
        DomesticPtr curr = dHead;
        if (c.cgpaVal[0] < 0 || c.cgpaVal[0] > 4.33)
        {
            cout << "invalid cgpa" << endl;
            return {};
        }
        switch(c.cgpaCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() > c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() < c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() <= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                break;
            }
            case 4:
            {
                if (c.cgpaVal[1] < 0 || c.cgpaVal[1] > 4.33) {
                    cout << "invalid cgpa" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0] && curr->get_cgpa() <= c.cgpaVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->d_getNext();
                }
                break;
            }
            default:
            {
                break;
            }
        }
        if(v.empty())
        {
            cout << "No Match Found in the list" << endl;
            return {};
        }
        else
        {
            if (c.rsVal[0] < 0 || c.rsVal[0]>100) {
                cout << "invalid research score" << endl;
                return {};
            }
            vector<DomesticStudent*> v_new;
            switch(c.rsCondition)
            {
                case 0:
                {
                    for(DomesticStudent* i: v)
                    {
                        if(i->getResearchScore() > c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 1:
                {
                    for(DomesticStudent* i: v)
                    {
                        if(i->getResearchScore() >= c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 2:
                {
                    for(DomesticStudent* i: v)
                    {
                        if(i->getResearchScore() < c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 3:
                {
                    for(DomesticStudent* i: v)
                    {
                        if(i->getResearchScore() <= c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 4:
                {
                    if (c.rsVal[1] < 0 || c.rsVal[1]>100) {
                        cout << "invalid research score" << endl;
                        return {};
                    }
                    for(DomesticStudent* i: v)
                    {
                        if(i->getResearchScore() >= c.rsVal[0] && i->getResearchScore() <= c.rsVal[1])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                default:
                {
                    return {};
                }
            }
        }
    }

    return {};
}

vector<InternationalStudent *> filter::getFilterResult(InternationalStudent *iHead, Conditions &c)
{
    if (iHead == nullptr)
    {
        //case list is empty
        cout << "List is Empty" << endl;
        return {};
    }

    //case list has atleast one object
    vector<InternationalStudent*> v;

    if(c.cgpaConditioned && !c.rsConditioned)
    {
        InternationalStudent* curr = iHead;
        if (c.cgpaVal[0] < 0 || c.cgpaVal[0] > 4.33)
        {
            cout << "invalid cgpa" << endl;
            return {};
        }
        switch(c.cgpaCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() > c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() < c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() <= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 4:
            {
                if (c.cgpaVal[1] < 0 || c.cgpaVal[1] > 4.33) {
                    cout << "invalid cgpa" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0] && curr->get_cgpa() <= c.cgpaVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            default:
            {
                return {};
            }
        }
    }
    if(!c.cgpaConditioned && c.rsConditioned)
    {
        InternationalStudent* curr = iHead;
        if (c.rsVal[0] < 0 || c.rsVal[0]>100) {
            cout << "invalid research score" << endl;
            return {};
        }
        switch(c.rsCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() > c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() >= c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() < c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() <= c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 4:
            {
                if (c.rsVal[1] < 0 || c.rsVal[1]>100) {
                    cout << "invalid research score" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->getResearchScore()>= c.rsVal[0] && curr->getResearchScore() <= c.rsVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            default:
            {
                return {};
            }
        }
    }
    if(c.cgpaConditioned && c.rsConditioned)
    {
        InternationalStudent* curr = iHead;
        if (c.cgpaVal[0] < 0 || c.cgpaVal[0] > 4.33)
        {
            cout << "invalid cgpa" << endl;
            return {};
        }
        switch(c.cgpaCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() > c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() < c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() <= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                break;
            }
            case 4:
            {
                if (c.cgpaVal[1] < 0 || c.cgpaVal[1] > 4.33) {
                    cout << "invalid cgpa" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0] && curr->get_cgpa() <= c.cgpaVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->i_getNext();
                }
                break;
            }
            default:
            {
                break;
            }
        }
        if(v.empty())
        {
            cout << "No Match Found in the list" << endl;
            return {};
        }
        else
        {
            if (c.rsVal[0] < 0 || c.rsVal[0]>100) {
                cout << "invalid research score" << endl;
                return {};
            }
            vector<InternationalStudent*> v_new;
            switch(c.rsCondition)
            {
                case 0:
                {
                    for(InternationalStudent* i: v)
                    {
                        if(i->getResearchScore() > c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 1:
                {
                    for(InternationalStudent* i: v)
                    {
                        if(i->getResearchScore() >= c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 2:
                {
                    for(InternationalStudent* i: v)
                    {
                        if(i->getResearchScore() < c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 3:
                {
                    for(InternationalStudent* i: v)
                    {
                        if(i->getResearchScore() <= c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 4:
                {
                    if (c.rsVal[1] < 0 || c.rsVal[1]>100) {
                        cout << "invalid research score" << endl;
                        return {};
                    }
                    for(InternationalStudent* i: v)
                    {
                        if(i->getResearchScore() >= c.rsVal[0] && i->getResearchScore() <= c.rsVal[1])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                default:
                {
                    return {};
                }
            }
        }
    }

    return {};
}

vector<Student *> filter::getFilterResult(Student *sHead, Conditions &c)
{
    if (sHead == nullptr)
    {
        //case list is empty
        cout << "List is Empty" << endl;
        return {};
    }

    //case list has atleast one object
    vector<Student*> v;

    if(c.cgpaConditioned && !c.rsConditioned)
    {
        Student* curr = sHead;
        if (c.cgpaVal[0] < 0 || c.cgpaVal[0] > 4.33)
        {
            cout << "invalid cgpa" << endl;
            return {};
        }
        switch(c.cgpaCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() > c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() < c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() <= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 4:
            {
                if (c.cgpaVal[1] < 0 || c.cgpaVal[1] > 4.33) {
                    cout << "invalid cgpa" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0] && curr->get_cgpa() <= c.cgpaVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            default:
            {
                return {};
            }
        }
    }
    if(!c.cgpaConditioned && c.rsConditioned)
    {
        Student* curr = sHead;
        if (c.rsVal[0] < 0 || c.rsVal[0]>100) {
            cout << "invalid research score" << endl;
            return {};
        }
        switch(c.rsCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() > c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() >= c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() < c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->getResearchScore() <= c.rsVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            case 4:
            {
                if (c.rsVal[1] < 0 || c.rsVal[1]>100) {
                    cout << "invalid research score" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->getResearchScore()>= c.rsVal[0] && curr->getResearchScore() <= c.rsVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                return v;
                break;
            }
            default:
            {
                return {};
            }
        }
    }
    if(c.cgpaConditioned && c.rsConditioned)
    {
        Student* curr = sHead;
        if (c.cgpaVal[0] < 0 || c.cgpaVal[0] > 4.33)
        {
            cout << "invalid cgpa" << endl;
            return {};
        }
        switch(c.cgpaCondition)
        {
            case 0:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() > c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                break;
            }
            case 1:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                if(v.empty())
                {
                    cout << "No Match Found in the list" << endl;
                }
                break;
            }
            case 2:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() < c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                break;
            }
            case 3:
            {
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() <= c.cgpaVal[0])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                break;
            }
            case 4:
            {
                if (c.cgpaVal[1] < 0 || c.cgpaVal[1] > 4.33) {
                    cout << "invalid cgpa" << endl;
                    return {};
                }
                while(curr != nullptr)
                {
                    if(curr->get_cgpa() >= c.cgpaVal[0] && curr->get_cgpa() <= c.cgpaVal[1])
                    {
                        v.push_back(curr);
                    }
                    curr = curr->getNext();
                }
                break;
            }
            default:
            {
                break;
            }
        }
        if(v.empty())
        {
            cout << "No Match Found in the list" << endl;
            return {};
        }
        else
        {
            if (c.rsVal[0] < 0 || c.rsVal[0]>100) {
                cout << "invalid research score" << endl;
                return {};
            }
            vector<Student*> v_new;
            switch(c.rsCondition)
            {
                case 0:
                {
                    for(Student* i: v)
                    {
                        if(i->getResearchScore() > c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 1:
                {
                    for(Student* i: v)
                    {
                        if(i->getResearchScore() >= c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 2:
                {
                    for(Student* i: v)
                    {
                        if(i->getResearchScore() < c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 3:
                {
                    for(Student* i: v)
                    {
                        if(i->getResearchScore() <= c.rsVal[0])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                case 4:
                {
                    if (c.rsVal[1] < 0 || c.rsVal[1]>100) {
                        cout << "invalid research score" << endl;
                        return {};
                    }
                    for(Student* i: v)
                    {
                        if(i->getResearchScore() >= c.rsVal[0] && i->getResearchScore() <= c.rsVal[1])
                        {
                            v_new.push_back(i);
                        }
                    }
                    if(v.empty())
                    {
                        cout << "No Match Found in the list" << endl;
                    }
                    return v_new;
                    break;
                }
                default:
                {
                    return {};
                }
            }
        }
    }

    return {};
}
