#include <iostream>
#include <string>
using namespace std;
//Running Time is O(mn)
//Check if the string strGiven is present in the string strMaster
int FindSubStringIndex(string strMaster, string strGiven)
{
    //strMaster position
    for(int posMaster = 0 ; ; posMaster++)
    {
        //strGiven position
        for(int posGiven = 0 ; ; posGiven++)
        {
            //Check if the posn has reached the strGiven's length
            //This happens if it is an empty or after all the characters match
            if(posGiven == strGiven.length()) return posMaster;
            
            //Check if the given string length exceeds the master string 
            //or check there is not sufficient character left in the master to
            //Check the give string
            if(posGiven + posMaster > strMaster.length()) return -1;
            
            //Check consecutive characters are present in the master if not then
            //break and start again. The current index of master till the length
            //of the given string
            if(strGiven[posGiven] != strMaster[posMaster + posGiven]) break;
            
        }
    }
}

int main()
{
    //Check if string present in another
    cout<<FindSubStringIndex("Hello","dll")<<endl;
}
