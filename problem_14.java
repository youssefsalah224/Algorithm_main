import java.util.Hashtable;
import java.util.Scanner;

public class problem14 {
    public static void getPairs(int arr[], int target) {
        int state = 0;
        Hashtable<Integer, Integer> Pairs = new Hashtable<Integer, Integer>();
        for (int i = 0; i < arr.length; i++) {
            int temp = target - arr[i];
            if (Pairs.containsKey(arr[i])) {
                state++;
                System.out.println("pair found");// hence we print all exist pairs because we don't sure doctor need
                                                 // only one pair or all pairs
                System.out.println("[ " + arr[i] + " , " + Pairs.get(arr[i]) + " ]");
            } else
                Pairs.put(temp, arr[i]);
        }
        if (state == 0)
            System.out.println("pair not found");
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int arr[] = { 2, 45, 7, 3, 5, 8, 9 };
        int target = 0;
        System.out.println("enter target...");
        target = input.nextInt();
        getPairs(arr, target);
    }
}
