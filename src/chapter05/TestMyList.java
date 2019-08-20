package chapter05;

public class TestMyList {
    public static void main(String[] args) {

        MyList<Integer> myList = new MyList<>(5);
        myList.insert(4);
        myList.insert(7);
        myList.insert(8);

        myList.display();

    }

}
