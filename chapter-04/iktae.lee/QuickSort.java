package chap04;

/**
 * 책의 퀵소트 소스 그대로
 */
public class QuickSort {
    public static void main(String[] args) {
        int a[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};

        quick(a, 0, a.length - 1);

        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }

    }

    private static void quick(int[] a, int left, int right) {
        int s, t, i, j;

        if (left < right) {
            s = a[(left + right) / 2];
            i = left - 1; j = right + 1;

            while (true) {
                while (a[++i] < s);
                while (a[--j] > s);

                if (i >= j) break;
                t = a[i]; a[i] = a[j]; a[j] = t;
            }

            quick(a, left, i - 1);
            quick(a, j + 1, right);
        }
    }
}
