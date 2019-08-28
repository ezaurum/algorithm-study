package chapter06;

import java.util.Scanner;

public class RomanDecoder {
    public static void main(String[] args) {
        System.out.print("input: ");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char[] romanStr = input.toCharArray();

        int output = 0;

        for (int i = 1; i < romanStr.length; i++) {
            output += ( toNumber(romanStr[i - 1]) < toNumber(romanStr[i])  ? -1 : 1 ) * toNumber(romanStr[i - 1]);
        }
        output += toNumber(romanStr[romanStr.length-1]);

        System.out.println("output: " + output);
    }

    private static int toNumber(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
}
