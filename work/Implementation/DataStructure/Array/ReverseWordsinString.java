import java.util.*;
import java.io.*;
public class ReverseWordsinString
{
    String ReverseWords(String inputString)
    {
        List<String> listWords = Arrays.asList(inputString.split(" "));
        Collections.reverse(listWords);
        String outputString = "";
        Iterator<String> listWordsItr = listWords.iterator();
        while (listWordsItr.hasNext()) 
        {   
            String currentWord = listWordsItr.next();
            if(!currentWord.isEmpty())
            {
                System.out.println("currentWord  " + currentWord);
    			outputString += currentWord;
    			if(listWordsItr.hasNext())
    			{
    			    outputString += " ";
    			}
            }
		}        
		/*
		//Left Trim
		outputString = outputString.replaceAll("^\\s+", "");
		//Right Trim
		outputString = outputString.replaceAll("\\s+$", "");
		*/
		System.out.println(outputString + " " + listWords.size());
        return outputString;
    }
    
    public static void main(String [] args)
    {
        HelloWorld objHelloWorld = new HelloWorld();
        objHelloWorld.ReverseWords("   Hey This is   Swaroop   ");
        //System.out.println(objHelloWorld.ReverseWords("Hey This is Swaroop"));
    }
};