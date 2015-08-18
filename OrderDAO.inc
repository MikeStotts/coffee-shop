<?php
require_once("Order.inc");

interface OrderDAO {
    function getAll();
    function get(int $id);
    function update($order);
    function delete($order);
    function add(Order $order);
}
?>
