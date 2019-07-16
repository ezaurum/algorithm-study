package chapter01;

/**
 * 점화식 nCr 재귀호출
 */
public class Exam1 {

    public static void main(String[] args) {

        for (int n = 0; n <= 5; n++) {
            for (int r = 0; r <= n; r++) {
                System.out.print(n + " C " + r + " = " + combi(n, r) + "\t");
            }
            System.out.println();
        }
    }

    private static long combi(double n, double r) {

        if (r == 0) {
            return 1;
        }
        else if (r == n) { // nCn은 1이므로 계산 단축을 위해...
            return 1;
        }
        else {
            return (long) ((n - r + 1) / r * combi(n, r - 1));
        }

    }
}
