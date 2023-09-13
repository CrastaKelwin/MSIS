class TestCircle{
    public static void main(String[] args) {
        Circle cir = new Circle();
        System.out.println(cir.toString());
        cir.setColor("blue");
        cir.setFilled();
        System.out.println(cir.toString());
        Circle cir2 = new Circle(5,"yellow",true);
        System.out.println(cir2.toString());
        System.out.println(cir2.getArea());
        System.out.println(cir2.getPerimeter());
    }
}