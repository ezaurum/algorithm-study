package chapter06;

public class Test {
    public static void main(String[] args) {
        BinaryTree biTree = new BinaryTree();

        // 생성
        biTree.genTree("Matilda");
        biTree.genTree("Candy");
        biTree.genTree("Rolla");
        biTree.genTree("Ann");
        biTree.genTree("Emy");
        biTree.genTree("Nancy");
        biTree.genTree("Eluza");
        biTree.genTree("Lisa");

        // 검색
        System.out.println(biTree.search("Rolla"));;
        System.out.println(biTree.search("Iktae"));;

        // 순회 - inorder
        biTree.inorderTraversal();

        // 순회 - lever
        biTree.levelTraversal();
    }


}
