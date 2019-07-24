package chapter02;

public class Exam15 {

    public static void main(String[] args) {
        double[][] a = {
                {2.0, 3.0, 1.0, 4.0},
                {4.0, 1.0, -3.0, -2.0},
                {-1.0, 2.0, 2.0, 2.0}};

        double d;
        int N = a.length;

        // 삼각화
        for (int k = 0; k < N - 1; k++) {
            for (int i = k + 1; i < N; i++) {
                d = a[i][k] / a[k][k];
                for (int j = k; j <= N; j++) {
                    a[i][j] = a[i][j] - a[k][j] * d;
                }
                printArray(a);
            }
        }

        // 후퇴대입
        for (int i = N - 1; i >= 0; i--) {
            d = a[i][N];
            for (int j = i + 1; j < N; j++) {
                d = d - a[i][j] * a[j][N];
            }
            a[i][N] = d / a[i][i];
        }

        printArray(a);
    }

    private static void printArray(double[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("-------------------");
    }

}
