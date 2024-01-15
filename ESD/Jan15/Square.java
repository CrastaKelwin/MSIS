class Square extends Rectangle {
    Square(){
        super();
    }
    Square(double side){
        super(side,side);
    }
    Square(double side,String color,boolean filled){
        super(side, side, color, filled);
    }

    double getSide()
    {
        return super.getLength();
    }

    void setSide(double side)
    {
        super.setLength(side);
        super.setWidth(side);
    }

    @Override
    public String toString() {
        return ("A Square of side = " + getSide() +", which is a " + super.toString());
    }
}