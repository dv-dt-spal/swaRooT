public class HelloWorld
{
static int indexI;
static int indexJ;
static boolean FindTwoSumIndex(int pindexI, int pindexJ, int piTarget, int[] numArray )
{
    if(numArray[pindexI] + numArray[pindexJ] == piTarget)
    {
        return true;
    }
    else if(pindexI == pindexJ || pindexI > pindexJ)
    {
        //cout<<"Invalid "<<pindexI<<" "<<pindexJ<<endl;
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
    throw new IllegalArgumentException("No Solution Found");
}    
    public static void main(String[] args)
    {
        System.out.println("Two Sum Sorted");
        int lnumArray[] = {2,3,4,5,6,7,9,80};
        int iTarget = 800;
        indexI = 0;
        indexJ = lnumArray.length-1;
        boolean isTwoSum = FindTwoSumIndex(indexI, indexJ, iTarget, lnumArray);
        if(isTwoSum)
        {
            System.out.println("Two Sum Sorted " + indexI + " " + indexJ );
        }
        else
        {
            System.out.println("Invalid");
        }
    }
}public class HelloWorld
{
static int indexI;
static int indexJ;
static boolean FindTwoSumIndex(int pindexI, int pindexJ, int piTarget, int[] numArray )
{
    if(numArray[pindexI] + numArray[pindexJ] == piTarget)
    {
        return true;
    }
    else if(pindexI == pindexJ || pindexI > pindexJ)
    {
        //cout<<"Invalid "<<pindexI<<" "<<pindexJ<<endl;
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
    throw new IllegalArgumentException("No Solution Found");
}    
    public static void main(String[] args)
    {
        System.out.println("Two Sum Sorted");
        int lnumArray[] = {2,3,4,5,6,7,9,80};
        int iTarget = 800;
        indexI = 0;
        indexJ = lnumArray.length-1;
        boolean isTwoSum = FindTwoSumIndex(indexI, indexJ, iTarget, lnumArray);
        if(isTwoSum)
        {
            System.out.println("Two Sum Sorted " + indexI + " " + indexJ );
        }
        else
        {
            System.out.println("Invalid");
        }
    }
}