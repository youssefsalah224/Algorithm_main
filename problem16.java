import java.util.Hashtable;

class problem16 {
    public static int[] sortWithOccurrence(int[] unSortedArray) {
        Hashtable<Integer, Integer> occurrence = new Hashtable<>();
        int[] sortedArray = new int[unSortedArray.length];

        for (int i : unSortedArray)
            occurrence.put(i, occurrence.getOrDefault(i, 0) + 1);

        int counter = 0;
        for (int i : unSortedArray) {
            if (occurrence.containsKey(i)) {
                int n = occurrence.get(i);
                while (n-- != 0) {
                    sortedArray[counter] = i;
                    counter++;
                }
                occurrence.remove(i);
            }
        }
        return sortedArray;
    }

    public static void main(String[] args) {
        int[] unSortedArray = { 1, 2, 3, 1, 2, 1 };
        // int[] unSortedArray = { 5, 4, 5, 5, 3, 1, 2, 2, 4 };

        System.out.println("Un Sorted Array is  ");
        for (int i : unSortedArray) {
            System.out.print(i);
            System.out.print(" ");
        }
        System.out.println();

        int[] sortedArray = sortWithOccurrence(unSortedArray);

        System.out.println("Sorted Array is  ");
        for (int i : sortedArray) {
            System.out.print(i);
            System.out.print(" ");
        }

    }

}
