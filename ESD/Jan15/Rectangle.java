/**
 * Rectangle
 */
public class Rectangle extends Shape{
    private double width;
    private double length;

    Rectangle(){
        super();
        this.length = 1.0;
        this.width=1.0;
    }

    Rectangle(double width, double length){
        super();
        this.length = length;
        this.width=width;
    }

    Rectangle(double width, double length,String color, boolean filled){
        super(color,filled);
        this.length = length;
        this.width=width;
    }

    public double getLength() {
        return length;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getArea(){
        return this.length * this.width;
    }

    double getPerimeter() {
        return ((2 * this.length) + (2 * this.width));
    }
    @Override
    public String toString() {
        return ("Rectangle with width = " + this.width + " and length = " + this.length + ", which is a "
                + super.toString());
    }
}