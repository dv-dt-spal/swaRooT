public class ATOI
{
    static int atoi(String number)
    {
        int pos = 0; 
        int strLen = number.length();
        while(pos < strLen && Character.isWhitespace(number.charAt(pos))) pos++;
        int sign = 1;
        if(pos < strLen && number.charAt(pos) == '-')
        {
            sign = -1;
            pos++;
        }
        else if (pos < strLen && number.charAt(pos) == '+')
        {
            sign = 1;
            pos++;
        }
        int iNumber = 0;
        int max = Integer.MAX_VALUE /10;
        while(pos < strLen && Character.isDigit(number.charAt(pos)))
        {
            int digit = Character.getNumericValue(number.charAt(pos));
            if(iNumber > max || iNumber == max && digit >= 8)
            return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            
            iNumber = iNumber * 10 + digit;
            pos++;
        }
        return iNumber;
    }
    

     public static void main(String []args)
     {
         System.out.println(atoi("       2147483647.123213dsahdasjh"));
     }
}
