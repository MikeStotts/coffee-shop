<?php
require_once("OrderItem.inc");

interface OrderItemDAO {
    function getAll();
    function get(int $id);
    function update(OrderItem $orderItem);
    function delete(OrderItem $orderItem);
    function add(Order $order, OrderItem $orderItem);
}
?>
