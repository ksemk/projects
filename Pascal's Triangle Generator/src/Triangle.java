import java.util.Scanner;

public class Triangle {

    public static void print_triangle(int N) {
        int[][] triangle = new int[N + 1][];
        for (int i = 0; i < N + 1; i++) {
            triangle[i] = new int[i + 1];
            triangle[i][0] = 1;
            triangle[i][triangle[i].length - 1] = 1;
        }
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < triangle[i].length - 1; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < triangle[i].length; j++) {
                System.out.print(triangle[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int N;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Give a triangle height: ");
        N = scanner.nextInt();
        if (N < 0) System.out.println("Invalid data");
        else print_triangle(N);
    }
}