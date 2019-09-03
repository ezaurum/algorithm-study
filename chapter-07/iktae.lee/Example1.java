package chapter07;

/**
 * 겹치는 간격 정리하기
 * 간격(interval)로 이루어진 배열이 주어지면, 겹치는 간격 원소들을 합친 새로운 배열을 만드시오. 간격은 시작과 끝으로 이루어져 있으며 시작은 끝보다 작거나 같습니다.
 * 예제)
 *
 * Input: {{2,4}, {1,5}, {7,9}}
 * Output: {{1,5}, {7,9}}
 *
 * Input: {{3,6}, {1,3}, {2,4}}
 * Output: {{1,6}}
 *
 */
public class Example1 {
    public static void main(String[] args) {
        int[][] input = {{3,6}, {1,3}, {2,4}};
        int[] output = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int i = 0; i < input.length; i++) {
            marking(input[i], output);
        }

        for (int i = 0; i < output.length; i++) {
            System.out.print(output[i]);
        }
    }

    private static void marking(int[] input, int[] output) {
        for (int i = input[0]; i <= input[1]; i++) {
            if (output[i] != 1) output[i] = 1;
        }
    }


}
