import java.io.*;
import java.util.*;
public class subconjuntos {

    public static void main(String[] args) {
        boolean res=true;
        String a= "";
        String b= "";
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
        		System.out.print("Si es un subconjunto de a");
        	}
        	else
        		System.out.print("No es un subconjunto de a");
         }
}
