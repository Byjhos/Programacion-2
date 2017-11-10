import java.io.*;
import java.util.*;
public class subconjuntos {
    public static void main(String[] args) {
        boolean res=true;
          String a= "abc";
          String b= "xadfbhdc";
        	for (int i = 0; i<a.length(); i++)
        	{
        		char d =a.charAt(i);
        		if(!b.contains(String.valueOf(d)))
        		{
        			res=false;
        			break;
        		}
        	}
        	if(res)
        	{
        		System.out.print("La cadena b si es un subconjunto de la cadena a");
        	}
        	else
        		System.out.print("La cadena b no es un subconjunto de la cadena a");
         }
}