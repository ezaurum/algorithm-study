package chap03;

import java.util.ArrayList;

/**
 * 정수 배열 (int array)가 주어지면
 * 가장 큰 이어지는(연속적인) 원소들의 합을 구하시오. 단, 시간복잡도는 O(n)
 *
 * ex)
 * Input: [-1, 3, -1, 5]
 * Output: 7 // 3 + (-1) + 5
 * Input: [-5, -3, -1]
 * Output: -1 // -1
 * Input: [2, 4, -2, -3, 8] => [6, -5, 8]
 * Output: 9 // 2 + 4 + (-2) + (-3) + 8
 * Input: [2, 1, -3, 4, -2, 8]
 * Output: 10 // 4 + (-2) + 8
 */
public class SumSubArray {
    public static void main(String[] args) {
        int[] input = {2, 1, -3, 4, -2, 8};
        boolean connect = true;
        ArrayList<Integer> outputList = new ArrayList<>();
        int outputSum = 0;
        ArrayList<Integer> minusList = new ArrayList<>();
        int minusSum = 0;

        for (int i = 0; i < input.length; i++) {
            // 최초 비어 있을 때
            if (outputList.size() == 0) {
                outputList.add(input[i]);
                outputSum += input[i];
                connect = input[i] > 0;
            }
            else {
                // 음수에 이어서 앞에 값보다 큰 값이 왔을 대
                if (!connect && input[i] > outputSum) {
                    outputList.clear();
                    outputList.add(input[i]);
                    outputSum = input[i];
                    connect = input[i] > 0;
                }
                // 양수에 이어서 양수(또는 이전 음수들의 합보다 큰 양수)가 왔을 때
                else if (input[i] > 0 && minusSum + input[i] > 0) {
                    outputList.addAll(minusList);
                    outputList.add(input[i]);
                    outputSum = outputSum + minusSum + input[i];

                    minusList.clear();
                    minusSum = 0;
                }
                // 양수에 이어서 (앞의 값보다 작은)음수가 왔을 때 - 보류
                else if (input[i] < 0 && outputSum + input[i] > 0) {
                    minusList.add(input[i]);
                    minusSum += input[i];
                }
                // 양수에 이어서 (앞의 값보다 큰)음수가 왔을 때
                else if (input[i] < 0 && outputSum + input[i] <= 0) {
                    connect = false;
                }
            }

        }

        System.out.print("Output: " + outputSum + " // ");
        for (int i = 0; i < outputList.size(); i++) {
            System.out.print(outputList.get(i) + ", ");
        }

    }
}
