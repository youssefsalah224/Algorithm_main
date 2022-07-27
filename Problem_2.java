package problem_2;
import java.util.Scanner;


public class Problem_2 {
    static long M_W,M_Z;

    static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low-1; 

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    static int quicksort(int arr[], int low, int high, int K) {
        int result=0 ;
        if(low == high){
        return arr[high];
        }
        else {

            int pi = partition(arr, low, high);
            int rank;
            rank= pi - low + 1;
            if (K == rank) {
                return arr[pi];
            } 
            if (K < rank) {
               return quicksort(arr, low, pi - 1, K);
            } else {
               return quicksort(arr, pi + 1, high, K-rank);

            }

        }


    }
    static long random(){
    
    M_Z=36969*(M_Z&65535)+(M_Z>>16);
    M_W=18000*(M_W&65535)+(M_W>>16);
    long res=(M_Z<<16)+M_W;
    return res%1000000000;
    }

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int n=0;
        int arr[];
        int K;
        
        System.out.printf("What's your inputs?...");
        n=input.nextInt();
        K=input.nextInt();
        M_W=input.nextLong();
        M_Z=input.nextLong();
        arr=new int[n];
        for (int i = 0; i < n; i++) {
            arr[i]=(int)random();
        }
        

        int result=quicksort(arr,0,arr.length-1,K);
        System.out.println("The Result is " + result);
        
      
    }
}


