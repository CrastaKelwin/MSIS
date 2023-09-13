class Square extends Rectangle {
    Square() {
        super();
    }

    Square(double side) {
        super(side, side);
    }

    Square(double side, String color, boolean filled) {
        super(side, side, color, filled);
    }

    double getSide() {
        return this.getLength();
    }

    void setSide(double side) {
        this.setLength(side);
    }

    @Override
    void setLength(double length) {
        super.setLength(length);
        super.setWidth(length);
    }

    @Override
    void setWidth(double width) {
        super.setLength(width);
        super.setWidth(width);
    }

    @Override
    public String toString() {
        return ("A Square with side = " + this.getLength() + ", which is a subclass of " + super.toString());
    }
}