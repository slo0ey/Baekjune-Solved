import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] vec = {new int[3], new int[3]};
        for(int i = 0; i < 6; i++) {
            vec[i/3][i%3] = sc.nextInt();
        }
        System.out.printf("%d %d %d", vec[1][0]-vec[0][2], vec[1][1] / vec[0][1], vec[1][2]-vec[0][0]);
    }
}