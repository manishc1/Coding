package elimdup;

import java.io.*;
import java.util.*;

import java.util.Hashtable;

public class ED {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String str = "";
		System.out.println("String :: ");
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try {
			str = reader.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		str = eliminateDuplicate(str);
		System.out.println("New String :: " + str);
	}
	
	public static String eliminateDuplicate(String str) {
		char[] s = str.toCharArray();
		Hashtable<Character,Integer> charHash = new Hashtable<Character,Integer>();
		int i,j;
		Integer val;
		
		for (i=0 ; i<s.length ; i++) {
			val = (Integer) charHash.get(s[i]);
			if (val == null)
				charHash.put(s[i], 1);
			else
				charHash.put(s[i] , val+1);
		}
		
		for (i=0,j=0 ; i<s.length ; i++) {
			val = (Integer) charHash.get(s[i]);
			if (val == 1) {
				s[j++] = s[i];
			}
			else if (val > 1) {
				s[j++] = s[i];
				charHash.put(s[i], -1);
			}
		}
		s[j] = '\0';
		
		return new String (s , 0 , j);
	}

}
