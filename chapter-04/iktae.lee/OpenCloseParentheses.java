package chap04;

import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

/**
 * [N쌍]의 괄호 조합은
 *   ▶ ( + [N-1쌍] + )
 *   ▶ () + [N-1쌍]
 *   ▶ [N-1]쌍] + ()
 * 그리고 N이 짝수면
 *   ▶ [N/2] + [N/2]
 * 으로 이루어짐
 *
 * 중복을 허용하지 않기 위해 Set을 사용해서 구현
 */
public class OpenCloseParentheses {
    public static void main(String[] args) {
        for (int i = 1; i <= 4; i++) {
            System.out.println(i + ": " + getParentheses(i));
        }

    }

    private static Set<String> getParentheses(int n) {
        Set<String> parenSet = new HashSet<>();

        if (n == 1) parenSet.add("()");
        else {
            parenSet.addAll(concatSet("(", getParentheses(n - 1), ")"));
            parenSet.addAll(concatSet("()", getParentheses(n - 1), ""));
            parenSet.addAll(concatSet("", getParentheses(n - 1), "()"));

            if (n % 2 == 0) {
                parenSet.addAll(concatSet(getParentheses(n / 2), getParentheses(n / 2)));
            }
        }

        return parenSet;
    }

    private static Collection<String> concatSet(Set<String> subSet1, Set<String> subSet2) {
        Set<String> newSet = new HashSet<>();

        for (String member1 : subSet1) {
            for (String member2 : subSet2) {
                newSet.add(member1+member2);
            }
        }
        return newSet;
    }

    private static Set<String> concatSet(String left, Set<String> printParentheses, String right) {
        Set<String> newSet = new HashSet<>();

        for (String member : printParentheses) {
            newSet.add(left+member+right);
        }
        return newSet;
    }
}
