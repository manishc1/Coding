package quickselect;

import java.util.*;

public class QS {

	public static int quickSelect(int[] arr, int k, int left, int right)
    {
            int pivot = (left + right) / 2;
            swap(arr, left, pivot);
            int last = left;
            // SAVING PIVOT ELEMENT AT LB LOCATION
            for (int i = left + 1; i <= right; i++)
            {
                    if (arr[i] < arr[left])
                            swap(arr, ++last, i);
            }
            // REPLACING PIVOT ELEMENT IN FINAL POSITION
            swap(arr, left, last);
            if (k <= last - 1 - left)
                return quickSelect(arr, k, left, last - 1);
        else if (k > (right - left) - (right - (last + 1)))
                return quickSelect(arr, k - ((right - left) - (right - (last + 1))), last + 1, right);
        else
                return arr[k];
    }

    private static void swap(int[] arr, int i, int j)
    {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
    }
    
    public static int[] generateRandomArray(int n)
    {

            Random r = new Random();
            int[] ar = new int[n];
            for (int i = 0; i < n; i++)
                    ar[i] = r.nextInt(100);

            return ar;

    }
    public static void printArray(int[] arr)
    {
            for (int i = 0; i < arr.length; i++)
                    System.out.print(arr[i] + " ");
            System.out.println();
            //System.out.println("sum=" + sumArray(arr));
    }
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = generateRandomArray(5);
		printArray(arr);
		quickSelect(arr, 3, 0, 4);
		printArray(arr);

	}

}
