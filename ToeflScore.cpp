//
// Created by larry on 18/06/2022.
//

#include "ToeflScore.hpp"

ToeflScore::ToeflScore()
{
    reading = -1;
    writing = -1;
    listening = -1;
    speaking = -1;
    total = -1;
}

ToeflScore::ToeflScore(const ToeflScore &score):ToeflScore(score.reading, score.writing, score.listening, score.speaking)
{

}

ToeflScore::ToeflScore(const int &readingIn, const int &writingIn, const int &listeningIn, const int &speakingIn)
{
    reading = readingIn;
    writing = writingIn;
    listening = listeningIn;
    speaking = speakingIn;
    total = reading + writing + listening + speaking;
}

int ToeflScore::getReading() const
{
    return reading;
}

int ToeflScore::getWriting() const
{
    return writing;
}

int ToeflScore::getListening() const
{
    return listening;
}

int ToeflScore::getSpeaking() const
{
    return speaking;
}

int ToeflScore::getTotal() const
{
    return total;
}

void ToeflScore::setReading(const int &readingIn)
{
    reading = readingIn;
}

void ToeflScore::setWriting(const int &writingIn)
{
    writing = writingIn;
}

void ToeflScore::setListening(const int &listeningIn)
{
    listening = listeningIn;
}

void ToeflScore::setSpeaking(const int &speakingIn)
{
    speaking = speakingIn;
}

string ToeflScore::toString() const
{
    return "Language: Reading: " + to_string(reading) + ", Writing: " + to_string(writing) + ", Listening: " + to_string(listening) + ", Speaking: " + to_string(speaking) + ", Total: " + to_string(total);
}

ostream &operator<<(ostream &os, const ToeflScore &score)
{
    os << score.toString();
    return os;
}

bool ToeflScore::operator==(const ToeflScore &score) const
{
    return reading == score.reading &&
           writing == score.writing &&
           listening == score.listening &&
           speaking == score.speaking;
}

bool ToeflScore::operator!=(const ToeflScore &score) const
{
    return !(score == *this);
}

bool ToeflScore::isDroppable() const
{
    return (reading < 20 || writing < 20 || listening < 20 || speaking < 20 || total < 93);
}
