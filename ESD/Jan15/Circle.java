
class Circle extends Shape {
    private double radius;

    Circle() {
        super();
        this.radius = 1.0;
    }

    Circle(double radius) {
        super();
        this.radius = radius;
    }

    Circle(double radius, String color, boolean filled) {
        super(color, filled);
        this.radius = radius;
    }

    public double getRadius() {
        return this.radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public String toString() {
        return ("A Circle with radius = "+ this.radius+", which is a "+ super.toString());
    }
}