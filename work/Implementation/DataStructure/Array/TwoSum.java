import java.util.*;
import java.io.*;
public class TwoSum
{
    //Find Two Sum Methos
    int[] FindTwoSum(int[] pNumArray, int pTargetSum)
    {
        //Declare the hashmap to fill in the data
        HashMap<Integer,Integer> twoSumMap = new HashMap<>();
        for(int pos = 0; pos < pNumArray.length; pos++ )
        {
            //Check if the hash map contains the data 
            if(twoSumMap.containsKey(pTargetSum - pNumArray[pos]) )
            {
                return new int[]{twoSumMap.get(pTargetSum - pNumArray[pos])+1,pos+1};
            }
            
            //Put the value in the map
            twoSumMap.put(pNumArray[pos],pos);
        }
        throw new IllegalArgumentException("No two sum solution");     
    }

    //Main Method
     public static void main(String []args)
     {
        //Declare array of numbers
        int NumArr[] = {4,3,2,6,7,9,0,10};
        
        //Init the scanner to get the target value
        Scanner scanData = new Scanner(System.in);
        System.out.println("Enter the target sum to be found");
        
        //Get the scan data as target sum
        int targetSum = scanData.nextInt();
        
        //Decalre the class object to call the functions
        TwoSum objTwoSum = new TwoSum();
        
        //Init the array to receive index
        int indexArr[] = new int[2];
        
        //Get the two sum index values
        indexArr = objTwoSum.FindTwoSum(NumArr,targetSum);
        
        System.out.println(indexArr[0] + " " + indexArr[1]);
     }
}
