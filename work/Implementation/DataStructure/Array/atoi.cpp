#include <iostream>
#include <string>
#include <climits>
using namespace std;
std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}
long check = INT_MAX/10;
long customatoi(string strNumber)
{
    //Remove whitespaces from left
    strNumber = trim(strNumber);
    
    //Check for signs in the beginning if any
    //Negative Sign
    bool isNegative = false;
    int negSign = strNumber.find_first_of("-");
    if(negSign == 0)
        isNegative = true;
        
    //Postive sign
    bool isPositive = false;
    int posSign = strNumber.find_first_of("+");
    if(posSign == 0)
        isPositive = true;
    
    if(isPositive || isNegative)
        strNumber = strNumber.substr(1);
    
    //find the alphanumeric characters till any invalid characters
    int firstNumeric = strNumber.find_first_of("0123456789");
    
    if(0 == firstNumeric)
    {
        int firstNotNumeric = strNumber.find_first_not_of("0123456789");
        strNumber = strNumber.substr(0,firstNotNumeric);
        cout<<"Final str "<<strNumber<<"\n";
        int iNumber = 0;
        for(int pos = 0; pos < strNumber.size(); pos++)
        {
            int digit = strNumber[pos] - '0';
            cout<<digit<<"\n";
            if(iNumber > check || iNumber == check && digit>=8)
            {
                return isNegative ? INT_MIN:INT_MAX; 
            }
            iNumber = iNumber * 10 + digit;
        }
        return isNegative ? -iNumber : iNumber;
        //Check for INT max or min value to avoid overflow
    }
    return INT_MAX;
}

int main()
{
   cout << "Hello World" << endl; 
   cout<<customatoi("   2147483641.-4dfdf");
   return 0;
}

