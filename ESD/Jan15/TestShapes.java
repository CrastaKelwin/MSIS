
/**
 * Test
 */
public class TestShapes {

    public static void main(String[] args) {
        Square sp = new Square(10,"Red",true);
        assert(sp.getArea()==100);
        System.out.println(sp.toString());
        assert(sp.getColor().equals("Red"));
        assert(sp.isFilled()==true);
        sp.setFilled(false);
        assert(sp.isFilled()==false);
        System.out.println(sp.toString());
    }
}