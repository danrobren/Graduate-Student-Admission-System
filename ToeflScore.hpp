#ifndef INTERIMREPORT_TOEFLSCORE_HPP
#define INTERIMREPORT_TOEFLSCORE_HPP

#include <iostream>

using namespace std;
class ToeflScore
{
private:
    int reading;
    int writing;
    int listening;
    int speaking;
    int total;
public:
    ToeflScore();
    ToeflScore(const ToeflScore &toeflScore);
    ToeflScore(const int &readingIn, const int &writingIn, const int &listeningIn, const int &speakingIn);

    int getReading() const;
    int getWriting() const;
    int getListening() const;
    int getSpeaking() const;
    int getTotal() const;

    void setReading(const int &readingIn);
    void setWriting(const int &writingIn);
    void setListening(const int &listeningIn);
    void setSpeaking(const int &speakingIn);

    bool isDroppable() const;

    string toString() const;

    friend ostream &operator<<(ostream &os, const ToeflScore &score);
    bool operator==(const ToeflScore &score) const;
    bool operator!=(const ToeflScore &score) const;
};


#endif //INTERIMREPORT_TOEFLSCORE_HPP
