public class FindSubString
{
    int FindSubStringIndex(String masterString, String stringToSearch)
    {
        for(int posMaster = 0 ; ; posMaster++)
        {
            for(int posSearch = 0 ; ; posSearch++)
            {
                if(posSearch == stringToSearch.length()) return posMaster;
                if(posSearch + posMaster == masterString.length()) return -1;
                if(stringToSearch.charAt(posSearch) != 
                    masterString.charAt(posMaster + posSearch)) break;
            }
        }
    }
    
    public static void main(String []args)
    {
        System.out.println("Find Sub string index with O(mn) run time");
        HelloWorld objHelloWorld = new HelloWorld();
        System.out.println(objHelloWorld.FindSubStringIndex("Hello","ellodsds"));
    }
}