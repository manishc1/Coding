+/*
Two very large numbers are represented using arrays. Multiply these two numbers. E.g. Two numbers 12 and 13 are represented as a=[1,2] adn b=[1,3]. The expected result is 12*13=156 i.e. c=[1,5,6]
*/
public static void multiplyTwoNumber(int[] A, int[] B){
        int[] C = new int[A.length+B.length];
        int s = C.length-1;
        
        for(int j=B.length-1; j>=0; j--) {
				int carry=0;
				int shift = s;
				for(int i=A.length-1; i>=0; i--) {
						int m = A[i]*B[j];
						int sum = m+C[shift]+carry;
						int num = sum%10;
						int c = sum/10;
						C[shift] = num;
						carry=c;
						shift--;
				}
				C[shift]=C[shift]+carry;            
				s--;            
        }
        printArray(C);
}
