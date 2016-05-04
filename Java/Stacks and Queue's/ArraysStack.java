package datastructures;

// @author iamsimranjot
// Implementation of Stacks using Arrays

public class Astack {

    private String arr[];
    private int top = 0;

    Astack() {

        arr = new String[1];
    }

    void resize(int capacity) {

        String[] copy = new String[capacity];

        for (int i = 0; i < top; i++) {
            copy[i] = arr[i];
        }

        arr = copy;
    }

    boolean isempty() {
        return (top == 0);
    }

    void push(String str) {

        if (top == arr.length) {
            resize(2 * arr.length);
        }

        arr[top++] = str;  // first add the string then increments
    }

    String pop() {

        String str = arr[--top];  //first decrements then assigns
        arr[top] = null;

        if (top > 0 && (top == arr.length / 4)) {
            resize(arr.length / 2);
        }
        return str;
    }
}
