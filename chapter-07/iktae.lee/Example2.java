package chapter07;

/**
 * 상위 k개만 소팅하기
 * 정수 배열(int array)이 주어지면 두번째로 큰 값을 프린트하시오.
 *
 * 예제)
 *
 * Input: [10, 5, 4, 3, -1]
 * Output: 5
 *
 * Input: [3, 3, 3]
 * Output: Does not exist.
 */
public class Example2 {
    public static void main(String[] args) {
        int[] input = {3,5,65,21,84,22,1,3,4,8,6,5,65,68,87,89,90,9,95};
        int first, second;
        HeapTree heapTree = new HeapTree(input.length);

        for (int i = 0; i < input.length; i++) {
            heapTree.addHeap(input[i]);
        }
        heapTree.displayHeap();

        first = heapTree.popHeap();

        do {
            second = heapTree.popHeap();
            if (first > second) {
                System.out.println("Output: " + second);
                break;
            }
        } while (second != 999);

        if (second == 999) {
            System.out.println("Output: Does not exist");
        }

    }
}
