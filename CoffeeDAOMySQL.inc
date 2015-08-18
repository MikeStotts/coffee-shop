<?php
require_once("CoffeeDAO.inc");

class CoffeeDAOMySQL implements CoffeeDAO {
    //TODO: Write getAll
    function getAll() {
        $coffees = array();
        include("dbstuff.inc");
        $cxn = mysqli_connect($host, $user, $password, $database)
            or die("Couldn't connect to server");
        $query = "select * from mlsn87_products";
        $result = mysqli_query($cxn, $query);
        if ($result) {
            while ($row = $result->fetch_assoc()) {
               $coffees[$row["id"]] = new Coffee($row["id"], $row["description"], $row["price"]);
            }
        }
       $result->close();
       $cxn->close();
      return $coffees; 
    }


    //TODO: Write get
    function get(int $id) {
    }

    //TODO: Write update
    function update(Coffee $coffee) {
    }

    //TODO: Write delete
    function delete(Coffee $coffee) {
    }

    //TODO: Write add
    function add(Coffee $coffee) {
    }

}
   
?>
