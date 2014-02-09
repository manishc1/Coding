package minstack;

import java.util.*;

public class CopyOfMinStack<Integer> extends Stack<Integer>{

		//private Stack<E> stack;
		private Stack<Integer> minStack;
		
		CopyOfMinStack() {
			//stack = new Stack<E>();
			super();
			minStack = new Stack<Integer>();
		}
		
		public Integer push(Integer val) {
			Integer currentMin;
			//stack.push(val);
			super.push(val);
			if(minStack.isEmpty())
				minStack.push(val);
			else {
				currentMin = minStack.peek();
				if (val.intValue() < currentMin.intValue())
					minStack.push(val);
			}
			return val;
		}
		
		public Integer pop() {
			//E val = stack.pop();
			Integer val = super.pop();
			if (val == minStack.peek())
				minStack.pop();
			return val;
		}
		
		public Integer peek() {
			//return stack.peek();
			return super.peek();
		}
		
		public Integer minimum() {
			return minStack.peek();
		}
}
