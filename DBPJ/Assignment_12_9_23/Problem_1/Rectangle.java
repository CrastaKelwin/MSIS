class Rectangle extends Shape {
    private double width, length;

    Rectangle() {
        this.length = 1.0;
        this.width = 1.0;
    }

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    Rectangle(double length, double width, String color, boolean filled) {
        super(color, filled);
        this.length = length;
        this.width = width;
    }

    double getLength() {
        return this.length;
    }

    double getWidth() {
        return this.width;
    }

    void setLength(double length) {
        this.length = length;
    }

    void setWidth(double width) {
        this.width = width;
    }

    double getArea() {
        return this.length * this.width;
    }

    double getPerimeter() {
        return ((2 * this.length) + (2 * this.width));
    }

    @Override
    public String toString() {
        return ("A Rectangle with width = " + this.width + " and length = " + this.length + ", which is a subclass of "
                + super.toString());
    }
}