/**
 * TestCalculator
 */
public class TestCalculator {
    public static void TestAddition() {
        System.out.println("running Addition tests");

        Calculator calc = BasicCalculator.getInstance();
        calc.put(10).put(25).add();
        assert (calc.read() == 35);
        calc.put(100).put(-25).add();
        assert (calc.read() == 75);
    }

    public static void main(String[] args) {
        TestAddition();
        Calculator calc = BasicCalculator.getInstance();
        System.out.println(calc.put(5).put(40).add().read());
        assert (calc.read() == 45);
        calc.clearAll();
        System.out.println(calc.put(80).put(40).div().read());
        assert (calc.read() == 2);
        System.out.println(calc.put(80).put(40).clear().put(100).div().read());
        assert (calc.read() == 0);
        calc.put(10).sub();
        System.out.println(calc.read());
        assert (calc.read() == -90);
        System.out.println(calc.neg().read());
        assert (calc.read() == 90);
        calc.clearAll();
        System.out.println(calc.put(10).put(12).mul().read());
        assert (calc.read() == 120);
    }
}