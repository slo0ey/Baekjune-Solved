import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ur = sc.nextInt();
        int tr = sc.nextInt();
        int u0 = sc.nextInt();
        int t0 = sc.nextInt();
        System.out.println(56*ur+24*tr+14*u0+6*t0);
    }
}