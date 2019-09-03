package chapter07;

public class Euler {
    static final int Root = 6;
    static final int Start = 1;

    static int[][] a = {{0,0,0,0,0},
                        {0,0,1,0,1},
                        {0,1,0,1,2},
                        {0,0,1,0,1},
                        {0,1,2,1,0}};

    static int success;
    static int[] stack = new int[Root + 1];
    static int n;

    public static void main(String[] args) {
        success = 0; n = Root;
        visit(Start);
        if (success == 0) {
            System.out.println("해가 없음");
        }
    }

    private static void visit(int i) {
        stack[n] = i;

        if (n == 0 && i == Start) {
            // 간선의 수만큼 통과한 후 원위치로 돌아오면
            System.out.print("해 " + ++success + " : ");
            for (i = 0; i <= Root; i++) {
                System.out.print(stack[i]);
            }
            System.out.println();
        }
        else {
            for (int j = 1; j < a.length; j++) {
                if (a[i][j] != 0) {
                    a[i][j]--; a[j][i]--;   // 지나간 간선을 제거한다
                    n--;
                    visit(j);
                    a[i][j]++; a[j][i]++;   // 간선을 되살린다
                    n++;
                }
            }
        }
    }
}
