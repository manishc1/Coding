/*
Give a min and max of an integer array, write a function to randomly return a number inside of this range, but not in the list. Also write a class that contains this function.
*/

int randomElement(int* A, int n, int min, int max) {
		int r = rand(max-min+1-n);
		int skipIndex = binarySearchWithIndex(A, n, r);
		skipIndex = skipIndex+1;
}
