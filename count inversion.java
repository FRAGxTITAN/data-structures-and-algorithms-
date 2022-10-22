// Java program to count
// inversions in an array

import java.io.*;

class Test {
	static int arr[] = new int[] { 1, 20, 6, 4, 5 };

	static int getInvCount(int n)
	{
		int inv_count = 0;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (arr[i] > arr[j])
					inv_count++;

		return inv_count;
	}

	// Driver method to test the above function
	public static void main(String[] args)
	{
		System.out.println("Number of inversions are "
						+ getInvCount(arr.length));
	}
}
