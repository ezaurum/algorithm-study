package chapter05;

public class MyList<T> {
    private T data;
    private MyList point;

    public MyList(T data) {
        this.data = data;
        this.point = null;
    }

    public void insert(T data) {
        if (this.point == null) {
            point = new MyList<>(data);
        }
        else {
            MyList here = this;
            while (here.point != null) {
                here = here.point;
            }
            here.point = new MyList<>(data);
        }
    }

    public void display() {
        MyList here = this;
        while (here != null) {
            System.out.print(here.data + " ");
            here = here.point;
        }

    }
}
