package chapter01;

/**
 * 몬테카를로법에 의한 π 계산
 */
public class Exam5 {

    private final static int NUM = 1000;

    public static void main(String[] args) {
        double x, y, pai;
        int a = 0;

        for (int i = 0; i <= NUM; i++) {
            x = Math.random();
            y = Math.random();

            // 원의 방정식
            if (x * x + y * y <= 1) {
                a++;
            }
        }

        pai = (double) 4 * a / NUM;
        System.out.println("π값 = " + pai);
    }
}
