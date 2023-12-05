import java.sql.*;

public class DBase {
    private Connection con = null;
    private Statement stm = null;
    public ResultSet res = null;

    int loadDriver() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            return 1;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return -1;
        }
    }

    int getConnection() {
        try {
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "");
            return 1;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return -1;
        }
    }

    int getStatement() {
        try {
            stm = con.createStatement();
            return 1;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return -1;
        }
    }

    int executeSQLQuery(String sql) {
        try {
            res = stm.executeQuery(sql);
            return 1;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return -1;
        }
    }
        int executeSQLcmd(String sql) {
        try {
            stm.executeUpdate(sql);
            return 1;
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return -1;
        }
    }

}
