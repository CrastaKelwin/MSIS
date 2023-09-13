
public class TestRectangle {
    public static void main(String[] args) {
        Rectangle rect1 = new Rectangle();
        Rectangle rect2 = new Rectangle(2.0, 45.5);
        Rectangle rect3 = new Rectangle(4.0, 5.0, "black", true);
        System.out.println(rect1);
        System.out.println(rect2);
        System.out.println(rect3);
        rect1.setColor("grey");
        rect1.setLength(8.0);
        rect1.setFilled();
        System.out.println(rect1);
        System.out.println(rect1.getPerimeter()+" "+rect1.getArea());
    }
}