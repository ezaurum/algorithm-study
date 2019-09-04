package chapter07;

public class HeapTest {
    public static void main(String[] args) {
        HeapTree heap = new HeapTree(100);

        heap.addHeap(10);
        heap.addHeap(25);
        heap.addHeap(30);
        heap.addHeap(15);
        heap.addHeap(26);
        heap.addHeap(35);
        heap.addHeap(20);
        heap.addHeap(29);
        heap.addHeap(12);

        heap.displayHeap();

        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
        System.out.println("top is: " + heap.popHeap());
        heap.displayHeap();
    }

}
