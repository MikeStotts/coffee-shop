<?php
include_once("Coffee.inc");
class CoffeeCollection {
    private $items = array();

    function __construct() {
        include ("dbstuff.inc");
        $cxn = mysqli_connect($host, $user, $password, $database)
            or die("Couldn't connect to server");
        $query = "SELECT * FROM mlsn87_products";
        $result = mysqli_query($cxn, $query);
        if ($result) {
            while ($row = $result->fetch_assoc()) {
                $this->items[$row["id"]] = new Coffee($row["id"], $row["description"], $row["price"]);
            }
        }
        $result->close();
    }

    function getItem($id) {
        return $this->items[$id];
    }

    function getItems() {
        return $this->items;
    }

}
?>
