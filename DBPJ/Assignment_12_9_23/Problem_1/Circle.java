
class Circle extends Shape {
    private double radius;

    Circle() {
        this.radius = 1.0;
    }

    Circle(double radius) {
        this.radius = radius;
    }

    Circle(double radius, String color, boolean filled) {
        super(color, filled);
        this.radius = radius;
    }

    double getRadius() {
        return this.radius;
    }

    void setRadius(double radius) {
        this.radius = radius;
    }

    double getArea() {
        return (Math.PI * this.radius * this.radius);
    }

    double getPerimeter() {
        return (2 * Math.PI * this.radius);
    }

    @Override
    public String toString() {
        return ("A Circle with radius = "+ this.radius+", which is a subclass of "+ super.toString());

    }
}