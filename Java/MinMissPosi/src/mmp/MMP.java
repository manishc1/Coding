package mmp;

import java.util.*;

public class MMP {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = {0,1,2,5,-99,3};
		findmmp(a);
	}
	
	public static void findmmp(int[] a) {
		HashMap inthash = new HashMap();
		
		for(int elem:a)
			if(elem>0 && elem<a.length+1)
				inthash.put(elem, 1);
		
		for(int i=1; i<a.length+1; i++)
			if(inthash.get(i) == null) {
				System.out.println(i);
				break;
			}
	}
}
