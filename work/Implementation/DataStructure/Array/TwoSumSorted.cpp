#include <iostream>
#include <array>
using namespace std;

static int indexI;
static int indexJ;
template<size_t SIZE>
bool FindTwoSumIndex(int pindexI, int pindexJ, int piTarget, array<int,SIZE> numArray )
{
    if(numArray[pindexI] + numArray[pindexJ] == piTarget)
    {
        return true;
    }
    else if(pindexI == pindexJ || pindexI > pindexJ)
    {
        cout<<"Invalid "<<pindexI<<" "<<pindexJ<<endl;
        return false;
    }
    else
    {
        if(numArray[pindexI] + numArray[pindexJ] < piTarget)
        {
            indexI++;
            return FindTwoSumIndex(indexI, pindexJ, piTarget, numArray);
        }
        else if(numArray[pindexI] + numArray[pindexJ] > piTarget)
        {
            indexJ--;
            return FindTwoSumIndex(pindexI, indexJ, piTarget, numArray);
        }
    }
}
int main()
{
    array<int,8> lnumArray = {2,3,4,5,6,7,9,80};
    int iTarget = 12;
    indexI = 0;
    indexJ = lnumArray.size()-1;
    bool isTwoSum = FindTwoSumIndex(indexI, indexJ, iTarget, lnumArray);
    if(isTwoSum)
    {
        cout<<"Index are "<<indexI<<" :: "<<indexJ<<endl;
    }
    else
    {
        cout<<"Invalid target"<<endl;
    }
}

