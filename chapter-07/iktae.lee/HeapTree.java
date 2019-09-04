package chapter07;

/**
 * 힙트리
 * 부모노드 > 자식노드
 */
public class HeapTree {
    private int[] heap;
    private int current;

    public HeapTree(int size) {
        this.heap = new int[size + 1];
        // Heap의 특성상, 배열의 첨자를 1로 하는게 편함
        // 부모 노드의 위치 p는 (s / 2)가 된다.
        this.current = 1;
    }

    public void addHeap(int item) {
        heap[this.current] = item;
        bubbleup(this.current);
        this.current++;
    }

    // 상향 이동
    private void bubbleup(int current) {
        int s = current;
        int p = s / 2;  // 부모 노드의 위치
        int tmp;

        while (s >= 2 && heap[p] < heap[s]) {  // 상향 이동
            tmp = heap[p]; heap[p] = heap[s]; heap[s] = tmp;
            s = p;
            p = s / 2;
        }
    }

    public int popHeap() {
        // Heap is empty
        if (this.current == 1) {
            return 999;
        }

        int p = 1;
        int s1 = p * 2;
        int s2 = s1 + 1;

        int retVal = heap[p];

        while (this.current > s1) {
            if (heap[s1] > heap[s2]) {
                heap[p] = heap[s1];
                p = s1;
            } else {
                heap[p] = heap[s2];
                p = s2;
            }
            s1 = p * 2;
            s2 = s1 + 1;
        }
        this.current--;

        // heap 모양이 깨지면서 부모자리로 이동했을 때, 빈자리 채우기
        if (this.current > p) {
            heap[p] = heap[this.current];
            bubbleup(p);
        }
        heap[this.current] = 0;

        return retVal;
    }

    public void displayHeap() {
        for (int i = 1; i < this.current; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
}
