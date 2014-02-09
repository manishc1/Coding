package qus;

import java.util.*;

public class Queue<E>
	{

	    private Stack<E> inbox = new Stack<E>();
	    private Stack<E> outbox = new Stack<E>();

	    public void queue(E item) {
	        inbox.push(item);
	    }

	    public E dequeue() {
	        if (outbox.isEmpty()) {
	            while (!inbox.isEmpty()) {
	               outbox.push(inbox.pop());
	            }
	        }
	        return outbox.pop();
	    }

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
