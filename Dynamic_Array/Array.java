import java.util.Scanner;

public class Array {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.print("Enter size of array: ");
    int size = in.nextInt();
    int[] a = new int[size];
    for (int i = 0; i < size; i++) {
      a[i] = i;
    }
    for (int i = 0; i < size; i++) {
      System.out.println(a[i]);
    }
  }
}