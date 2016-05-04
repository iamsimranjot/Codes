package datastructures;

// @author iamsimranjot
// Generic Implementation of Stacks using Arrays

public class AGstack<Item> {
    
    private Item arr[];
    private int top = 0;

    AGstack() {

        arr = (Item[])new Object[1]; // Generic array creation is not allowed in java so we have to cast it
    }

    void resize(int capacity) {

        Item[] copy = (Item[])new Object[capacity]; // Generic array creation is not allowed in java so we have to cast it

        for (int i = 0; i < top; i++) {
            copy[i] = arr[i];
        }

        arr = copy;
    }

    boolean isempty() {
        return (top == 0);
    }

    void push(Item str) {

        if (top == arr.length) {
            resize(2 * arr.length);
        }

        arr[top++] = str;  // first add the string then increments
    }

    Item pop() {

        Item str = arr[--top];  //first decrements then assigns
        arr[top] = null;

        if (top > 0 && (top == arr.length / 4)) {
            resize(arr.length / 2);
        }
        return str;
    }
    
}
