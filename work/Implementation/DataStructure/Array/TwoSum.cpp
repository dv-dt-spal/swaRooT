#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

void FindTwoSum(int pNumArray[],int target,int size,int** pOutIndexArray)
{
    map<int,int> l_mapTwoSum;
    for(int pos = 0 ; pos < size; pos++)
    {
        if(l_mapTwoSum.find(target - pNumArray[pos]) != l_mapTwoSum.end())
        {
             // showing contents:
            std::cout << "mymap contains:\n";
            for (map<int,int>::iterator it=l_mapTwoSum.begin(); it!=l_mapTwoSum.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    
            *pOutIndexArray = new int[2];
            int index0 = (int)l_mapTwoSum.find(target - pNumArray[pos])->second+1;
            pOutIndexArray[0][0] = index0;
            pOutIndexArray[0][1] = pos+1;
            return;
        }
        l_mapTwoSum.insert(pair<int,int>(pNumArray[pos],pos));
        cout<<"Map "<<l_mapTwoSum.size()<<endl;;
    }
    *pOutIndexArray = NULL;
}

int main()
{
    int numArray[] = {2,13,1,7,5,0,20};
    int target = 8;
    int size = sizeof(numArray)/sizeof(numArray[0]);
    int* indexArray;
    FindTwoSum(numArray,target,size,&indexArray);
    if(indexArray != NULL)
    {
        cout<<*indexArray<<endl;
        indexArray++;
        cout<<*indexArray<<endl;
    }
}

