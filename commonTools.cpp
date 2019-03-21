#include "commonTools.h"

std::vector <std::string> splitString(std::string givenString)
{	

    std::istringstream iss(givenString);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
    return results;
}

std::vector <std::string> refineString(std::string givenString)
{
    std::vector <std::string> myStrings;
    myStrings = splitString(givenString);
    for(int i = 0; i < myStrings.size(); i+=2)
    {
        if(myStrings[i][0] != '-')
            throw BadFormatEx();
        myStrings[i] = myStrings[i].substr(1);
    }
    return myStrings;
}

int Gstoi(std::string s)
{
    int my_num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        my_num = (my_num - 48 + s[i]) * 10;
    }
    return my_num / 10;
}

bool isUnique(std::vector <int> allNums, int newNum)
{
    for(int i = 0; i < allNums.size(); i++)
    {
        if(allNums[i] == newNum)
            return false;
    }
    return true;
}

std::vector <int> generateUniqueRandomNums(int max, int count)
{
    std::vector <int> allNums;
    int randomNum;
    for(int i = 0; i < count; i++)
    {
        do{
            randomNum = rand() % max;
        } while(!isUnique(allNums, randomNum));
    allNums.push_back(randomNum);
    }
    return allNums;
}

bool isUniqueVector(std::vector<std::string> strings)
{
    for(int i = 0; i < strings.size()-1; i++)
    {
        for(int j = i+1; j < strings.size(); j++)
        {
            if (strings[i] == strings[j])
                return false;
        }
    }
    return true;
}

void addVectorToVector(std::vector <std::string> &firstVec, std::vector <std::string> &secondVec)
{
    for(int i = 0; i < firstVec.size(); i++)
        secondVec.push_back(firstVec[i]);
}
