class TestShape {
    public static void main(String[] args) {
        Shape sh = new Shape();
        Shape sh2 = new Shape("Green", true);
        System.out.println(sh.toString());
        System.out.println(sh2.toString());

        sh.setColor("red");
        sh.setFilled();
        System.out.println(sh.toString());
        System.out.println(sh.getColor() + " " + sh.isFilled());
    }
}