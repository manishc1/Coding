package minstack;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MinStack m = new MinStack();
		m.push(1);
		m.push(2);
		m.push(0);
		//m.pop();
		System.out.println(m.minimum());

	}

}
