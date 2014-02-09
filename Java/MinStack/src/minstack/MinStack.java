package minstack;

import java.util.*;

public class MinStack {

		private Stack<Integer> stack;
		private Stack<Integer> minStack;
		
		MinStack() {
			stack = new Stack<Integer>();
			minStack = new Stack<Integer>();
		}
		
		public void push(Integer val) {
			Integer currentMin;
			stack.push(val);
			if(minStack.isEmpty())
				minStack.push(val);
			else {
				currentMin = minStack.peek();
				if (val < currentMin)
					minStack.push(val);
			}
		}
		
		public Integer pop() {
			Integer val = stack.pop();
			if (val == minStack.peek())
				minStack.pop();
			return val;
		}
		
		public Integer peek() {
			return stack.peek();
		}
		
		public Integer minimum() {
			return minStack.peek();
		}
}
