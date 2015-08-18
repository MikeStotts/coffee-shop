<?php
require_once("Coffee.inc");

interface CoffeeDAO {
    function getAll();
    function get(int $id);
    function update(Coffee $coffee);
    function delete(Coffee $coffee);
    function add(Coffee $coffee);
}
   
?>
