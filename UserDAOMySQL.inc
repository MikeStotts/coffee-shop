<?php
require_once("UserDAO.inc");

class UserDAOMySQL implements UserDAO {
    //TODO: Write getAll
    function getAll() {
    }

    //TODO: Write get
    function get($name) {
        include("dbstuff.inc");
        $cxn = mysqli_connect($host, $user, $password, $database)
            or die("Couldn't connect to server");
        //TODO: Use prepared statement for query
        $query = "select * from mlsn87_users
            where username='$name'";

        $result = mysqli_query($cxn, $query)
            or die("Couldn't execute query");
        $row = mysqli_fetch_assoc($result);
        if ($row == null) {
            $result->close();
            $cxn->close();
            return null;
        }
        $u = User::newUser(
            $row["customer_id"],
            $row["username"],
            $row["password"],
            $row["first"],
            $row["last"],
            $row["address"],
            $row["zip"],
            $row["phone"],
            $row["cc"],
            $row["cc_type"]
        );
        return $u;
    }

    //TODO: Write update
    function update(User $user) {
    }

    //TODO: Write delete
    function delete(User $usr) {
    }

    //TODO: Write add
    function add(User $user) {
    }

}
?>
