package modefreq;

import java.util.*;
import java.io.*;

public class Frequency {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] a = new int[100];
		int i , n = 0;
		
		System.out.println("Limit :: ");
		BufferedReader reader = new BufferedReader (new InputStreamReader(System.in));
		try {
			n =  Integer.parseInt(reader.readLine());
		} catch(IOException e) {
			e.printStackTrace();
		}

		for (i = 0 ; i < n ; i++) {
			System.out.println("a[" + i + "] :: ");
			BufferedReader reader1 = new BufferedReader (new InputStreamReader(System.in));
			try {
				a[i] =  Integer.parseInt(reader1.readLine());
			} catch(IOException e) {
				e.printStackTrace();
			}	
		}
		
		getFrequency(a , n);
	}

	public static void getFrequency(int[] a , int n) {
		int i;
		Integer val=0 , modefreq = 0;
		Hashtable<Integer, Integer> freqhash = new Hashtable<Integer , Integer>();
		
		for (i=0 ; i<n ; i++) {
			val = freqhash.get(a[i]);
			if(val == null)
				freqhash.put(a[i] , 1);
			else
				freqhash.put(a[i], val+1);
		}
		
		modefreq = freqhash.get(a[0]);
		
		for(i=0;i<n;i++) {
			val = freqhash.get(a[i]);
			if (val>modefreq)
				modefreq = val;
		}
		
		for (i=0;i<n;i++) {
			val = freqhash.get(a[i]);
			if (val == modefreq)
				System.out.println(a[i] + " " + freqhash.get(a[i]) + " mode");
			else if (val > 0)
				System.out.println(a[i] + " " + freqhash.get(a[i]));
			freqhash.put(a[i],-1);
		}
	}
}
