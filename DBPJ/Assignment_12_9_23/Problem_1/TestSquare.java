/**
 * TestSquare
 */
public class TestSquare {

    public static void main(String[] args) {
        Square sq1 = new Square();
        System.out.println(sq1);
        Square sq2 = new Square(4.0);
        System.out.println(sq2);
        sq2.setLength(5.0);
        System.out.println(sq2.getArea());
        sq2.setColor("green");
        sq2.setFilled();
        System.out.println(sq2);
        sq2.setSide(2.0);
        System.out.println(sq2);
    }
}