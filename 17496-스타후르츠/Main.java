import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int T = sc.nextInt();
        int C = sc.nextInt();
        int P = sc.nextInt();
        int days = 1;
        int sum = 0;
        while((days+=T) <= N) {
            sum += C*P;
        }
        System.out.println(sum);
    }
}