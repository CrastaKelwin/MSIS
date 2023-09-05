import java.lang.*;;

class Author {
    private String name;
    private String email;
    private char gender;

    Author(String name, String email, char gender) {
        this.email = email;
        this.gender = gender;
        this.name = name;
    };

    @Override
    public String toString() {
        return ("Name = " + name + ", Email = " + email + ", Gender = " + gender);
    }
}