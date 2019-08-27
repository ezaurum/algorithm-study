package chapter06;

public class BinaryTree {
    private Node root;

    public void genTree(String data) {
        root = genTree(root, data);
    }

    public boolean search(String data) {
        return search(root, data);
    }

    public void inorderTraversal() {
        inorderTraversal(root);
        System.out.println();
    }

    public void levelTraversal() {
        levelTraversal(root);
    }

    private Node genTree(Node current, String data) {
        if (current == null) {
            return new Node(data);
        }
        else if (data.compareTo(current.data) < 0) {
            current.left = genTree(current.left, data);
        }
        else {
            current.right = genTree(current.right, data);
        }
        return current;
    }

    private boolean search(Node current, String data) {
        if (current == null) {
            return false;
        }
        else if (data.equals(current.data)) {
            return true;
        }
        else if (data.compareTo(current.data) < 0) {
            return search(current.left, data);
        }
        else  {
            return search(current.right, data);
        }


    }

    private void inorderTraversal(Node current) {
        if (current != null) {
            inorderTraversal(current.left);
            System.out.print(current.data + " ");
            inorderTraversal(current.right);
        }
    }

    private void levelTraversal(Node current) {
        Node q[] = new Node[128]; // 포인터 테이블
        Node w[] = new Node[128]; // 임시 작업용
        int n;
        int level = 0;
        int child = 1;
        q[0] = current;
        do {
            n = 0;
            System.out.print("level " + level + ": ");
            for (int i = 0; i < child; i++) {
                System.out.print(q[i].data + "\t"); // 노드 출력
                // 바로 아래 레벨의 자식 노드를 가리키는 포인터를 스택에 저장
                if (q[i].left != null) {
                    w[n++] = q[i].left;
                }
                if (q[i].right != null) {
                    w[n++] = q[i].right;
                }
            }
            System.out.println();
            child = n;
            for (int i = 0; i < child; i++) {
                q[i] = w[i];
            }
            level++;
        } while (child != 0);
    }

    private class Node {
        private String data;
        private Node left;
        private Node right;

        public Node(String data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
}
