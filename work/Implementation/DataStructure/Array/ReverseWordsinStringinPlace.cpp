#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

//Function to reverse a string
void ReverseWordsinStrinPlace(char* inputString)
{
    //Reverse the entire string
    reverse(inputString,inputString + strlen(inputString));
    
    //Space length
    int currentspaceLength = 0;
    int lastspaceLength = 0;
    
    //Reverse individual words
    for(int pos = 0 ; pos < strlen(inputString);pos++ )
    {
        //Increment no of character till space
        currentspaceLength++;
        
        //Either there is a space or it reaches the end of the string
        if(inputString[pos] ==  ' ' )
        {
            //Reverse the entire till the space
            reverse(inputString + lastspaceLength,
                    inputString + currentspaceLength - 1);
            lastspaceLength = currentspaceLength;
        }
        else if(pos == strlen(inputString)-1)
        {
             //Reverse the entire till the space
             cout<<currentspaceLength << " + "<<lastspaceLength<<endl;

            reverse(inputString + lastspaceLength,
                    inputString + currentspaceLength);
        }
    }
}



int main()
{
   string inputData = "Hello World! Swaroop Pal yes";
   ReverseWordsinStrinPlace((char*)inputData.c_str());
   cout<<inputData<<endl;
   return 0;
}

