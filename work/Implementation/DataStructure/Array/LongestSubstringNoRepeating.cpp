#include <iostream>
#include <string>
using namespace std;

//Trim
string trim(const string& inputString,
            const string& whitespace  = " \t")
{
    auto firstNonSpace = inputString.find_first_not_of(whitespace);
    if(firstNonSpace == string::npos)
        return "";
    auto lastNonSpace = inputString.find_last_not_of(whitespace);
    return inputString.substr(firstNonSpace,lastNonSpace - firstNonSpace +1);
}

//Reduce 
std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t")
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}

string FindLargestSubString(string inputString)
{
    //Trim the white spaces
    inputString = trim(inputString);
    int currentLength{1};
    string currentString{inputString[0]};
    
    //Check if single or no character in the string
    if(inputString.size() == 0 || inputString.size() == 1)
    {
        return inputString;
    }
    
    string outputString{""};
    for(int pos = 0; pos <= inputString.size() - 2; pos++ )
    {
        if(inputString[pos] != inputString[pos+1])
        {
            currentLength++;
            currentString = currentString + inputString[pos+1];
            cout<<"currentString "<< inputString[pos]<<" " <<currentString<<"\n";
        }
        else
        {
            if(currentLength > outputString.size())
            {
                outputString = currentString;
                cout<<"Output "<<outputString<<"\n";
            }
            currentLength = 1;
            currentString = inputString[pos];
        }
    }
    if(currentLength > outputString.size())
    {
        outputString = currentString;
        cout<<"Output "<<outputString<<"\n";
    }
    return outputString;
}


int main()
{
   cout << "Longest SubString "<<FindLargestSubString("qazwsxedcrfvtgyhnujmiklopsafradqaaaaaqazwsxedcrfvtgyhnujmiklopsdmoihjukihgdsgundebdkjfksjglknsfjnsa;fas;fdkfhdijndfafradddddfergvtddddgsdmoihjukihgdsgundebdkjfksjglknsfjnsa;fas;fdkfhdijndf") << endl; 
   
   return 0;
}

