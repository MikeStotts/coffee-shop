<?php
include_once("User.inc");
include_once("Coffee.inc");
include_once("CoffeeDAOMySQL.inc");
include_once("OrderItem.inc");
include_once("Order.inc");
session_start();
$auth = $_SESSION["auth"];
if ($auth != "yes")
{
    $message = "Must login in first";
    session_destroy();
    include ("login.inc");
    exit();
}
$user = unserialize($_SESSION["user"]);
//TODO: validate and process input (build shopping cart)

$coffeeDAO = new CoffeeDAOMySQL();
$coffeeItems = $coffeeDAO->getAll();
$orders = new Order($user);
$total = 0;
foreach ($_POST as $id => $quantity) {
    if ($quantity > 0) {
        $item = $coffeeItems[$id];
        $price = $item->getPrice();
        $orders->addItem(new OrderItem($item, $quantity));
        $total += $price * $quantity;
    }
}
$orders->setTotal($total);
$_SESSION["orders"] = serialize($orders);
include("checkout.inc");
?>
