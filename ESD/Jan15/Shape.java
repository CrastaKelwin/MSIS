class Shape {
    private String color;
    private boolean filled;

    Shape() {
        this.color = "None";
        this.filled = false;
    }
    Shape(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }

    public String getColor() {
        return this.color;
    }

    public boolean isFilled() {
        return this.filled;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    @Override
    public String toString() {
        return ("Shape with color of " + this.color + " and " + (this.filled ? "filled" : "not filled"));
    }
}