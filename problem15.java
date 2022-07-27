import java.util.Hashtable;

public class problem14 {
    public static int findMinIndexOfRepating(int arr[], int size) {
        int minIndex = size;
        Hashtable<Integer, Integer> hash = new Hashtable<Integer, Integer>();
        for (int i = size - 1; i >= 0; i--) {
            if (hash.contains(arr[i]))
                minIndex = i;
            else
                hash.put(i, (arr[i]));
        }
        return minIndex;
    }

    public static void main(String[] args) {
        int arr[] = { 5, 6, 3, 4, 3, 6, 4 };
        // int arr[] = { 1, 2, 3, 4, 5, 6 };
        int size = arr.length;
        int minIndex = findMinIndexOfRepating(arr, size);
        if (minIndex != size)
            System.out.println("The minimum index of the repeating element is " + minIndex);
        else
            System.out.println("Invalid Input");
    }
}
