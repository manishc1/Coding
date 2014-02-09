package interview;

public class interview1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}


public class MinStack() extends Stack {
    Integer[] a;
    
    public void push(int val) {
        super.push(val);
        int i=0,index;
        while(a[i]<val) {
            i++;
        }
        index=i;
        i=a.length;
        while(i>index){
            a[i+1] = a[i];
            i--;
        }
        a[index] = val;
    }
    
    public int pop() {
        val = super.pop();
        int i=0,index;
        while (a[i]!=val)
            i++;
        while(i<a.length()) {
            a[i] = a[i+1];
            i--;
        }
        return val;
    }
    
    public int min() {
        if (a.length())
            return a[0];
        return -1; //invalid
    }
}