package chapter05;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Palindrome {

    public static void main(String[] args) {
        MyStack stack = new MyStack(100);
        MyQueue queue = new MyQueue(100);

        System.out.print("Input: ");
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();

        char[] s = input.toCharArray();
        for (char c : s) {
            stack.push(c);
            queue.enqueue(c);
        }

        boolean isPalindrome = true;
        for (int i = 0; i < s.length / 2; i++) {
            if (stack.pop() != queue.dequeue()) {
                isPalindrome = false;
                break;
            }
        }

        System.out.println("Output: " + isPalindrome);
    }
}
