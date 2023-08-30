class Stack {
    private int index;
    private int stack[];

    // default Constructor
    Stack() {

    }

    Stack(int size) {
        this.stack = new int[size];
    }

    public void display() {
        for (int index = 0; index < this.index; index++) {
            System.out.println("i : " + index + ", data : "+ this.stack[index]);
        }
    }

    public Boolean push(int data) {
        if (this.stack.length == index) {
            return false;
        }
        this.stack[this.index] = data;
        this.index++;
        return true;
    }

    public int pop() {
        if (this.index > 0) {
            this.index--;
            return this.stack[this.index];
        }
        return -1;
    }
}
