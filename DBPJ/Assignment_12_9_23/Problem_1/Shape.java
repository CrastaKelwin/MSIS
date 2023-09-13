class Shape {
    private String color;
    private boolean is_filled;

    Shape(String color, boolean is_filled) {
        this.color = color;
        this.is_filled = is_filled;
    }

    Shape() {
        this.is_filled = false;
    }

    public String getColor() {
        return this.color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return this.is_filled;
    }

    public void setFilled() {
        this.is_filled = true;
    }

    @Override
    public String toString() {
        return ("A Shape with color of " + this.color + " and " + (this.is_filled ? "filled" : "not filled"));
    }
}