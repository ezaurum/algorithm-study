package chap03;

import java.util.Scanner;

/**
 * 피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다.
 * 정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구하여라
 *
 * ex)
 * Input: N = 12
 * Output: 10 // 0, 1, 1, 2, 3, 5, 8 중 짝수인 2 + 8
 *
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
 *
 * 피보나치
 * x = 0, f(x) = 0
 * x = 1, f(x) = 1
 * x = n, f(x) = f(n-2) + f(n-1)
 */
public class SumEvenFibonacci {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Input: ");
        int n = scanner.nextInt();
        int i = 0;
        int fn = 0;
        int sum = 0;

        while (fn < n) {
            fn = fibonacci(i);
            if (fn % 2 == 0) {
                sum += fn;
            }
            i++;
        }

        System.out.println("Output: " + sum);
    }

    private static int fibonacci(int x) {
        if (x == 0) return 0;
        else if (x == 1) return 1;
        else return fibonacci(x - 2) + fibonacci(x - 1);
    }

}