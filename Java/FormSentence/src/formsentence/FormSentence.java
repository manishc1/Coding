/*
 * Given a sentence and a function isValidDictionaryword(String s),
 * which returns true if the word is present in dictionary.
 * WAP to separate valid dictionary words in the sentence with a space.
 * I/P : thereisastoneontheroad.
 * O/P : there is a stone on the road.
 */

package formsentence;

import java.util.*;

public class FormSentence {
	static Stack<String> stack;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		stack = new Stack<String>();
		String str = "thereisastoneontheroad";
		String sentence = new String();

		getSentence(str);
		
		while(!stack.isEmpty())
			sentence = sentence.concat(stack.pop().concat(" "));
		System.out.println(sentence);
	}

	public static boolean getSentence(String s) {

		if (s.length() == 0)
			return true;
		
		for (int i=0; i<=s.length(); i++) {
			if (isValidDictionaryWord(s.substring(0,i))){
				if (getSentence(s.substring(i))){
					//System.out.println("pushing " + s.substring(0,i) + " of " + s);
					stack.push(s.substring(0,i));
				}
			}
		}
		return true;
	}
	
	public static boolean isValidDictionaryWord(String s) {
		if (s.equals("there") || s.equals("is") || s.equals("a") || s.equals("stone") || s.equals("on") || s.equals("the") || s.equals("road"))
			return true;
		return false;
	}
}
