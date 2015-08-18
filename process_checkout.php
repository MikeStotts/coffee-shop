<?php
session_start();
// Write order to database
// 1. order table
//      1. invoice # (auto increments)
//      2. date
//      3. customer_id
//      3. total price
// 2. write order items
//      1. id   (auto increments)
//      2. invoice (refs mlsn87_orders(invoice))
//      3. product (refs mlsn87_products(id)),
//      4. quantity
require_once("User.inc");
require_once("Coffee.inc");
require_once("Order.inc");
require_once("OrderDAOMySQL.inc");
$orders = unserialize($_SESSION["orders"]);
$orderDAO = new OrderDAOMySQL();
$orderDAO->add($orders);
include("checkedout.inc");

$_SESSION = array();
session_destroy();
?>
