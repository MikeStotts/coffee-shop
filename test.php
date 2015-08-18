<?php
include("User.inc");
include("Coffee.inc");
include("OrderItem.inc");
include("Order.inc");

$hazel = new Coffee("hazelnut", "Hazelnut Cream", 3.59);
$vanilla = new Coffee("vanilla", "French Vanilla", 3.94);
$colombian = new Coffee("colombian", "Colombian", 5.05);

var_dump($hazel);
var_dump($vanilla);
var_dump($colombian);

$orHazel = new OrderItem($hazel);
$orVanilla = new OrderItem($vanilla);
$orHazel->increase(1);
$orVanilla->increase(2);

var_dump($orHazel);
var_dump($orVanilla);

printf("%0.2f\n", $orHazel->getCost());
printf("%0.2f\n", $orVanilla->getCost());

$u = User::getUser("mlsn87");

$v = User::newUser(0, 1, 2, 3, 4, 5,6, 7, 8, 9);
var_dump($u);
var_dump($v);

$or = new Order($u);
var_dump($or);

$or->addItem($orHazel);
$or->addItem($orVanilla);

?>
