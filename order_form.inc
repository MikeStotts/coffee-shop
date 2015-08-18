<?php
/* Program: order.inc
 * Description: Display order form
 */
require_once("User.inc");
require_once("Order.inc");
require_once("OrderItem.inc");
if (!isset($_SESSION) ||  $_SESSION["auth"] != "yes")
{
    $message = "Must login to order";
    include("login.inc");
    exit();
}

$auth = $_SESSION["auth"];
$user = unserialize($_SESSION["user"]);
$name = $user->getFirst();
require_once("CoffeeDAOMySQL.inc");
$coffeeDAO = new CoffeeDAOMySQL();
$items = $coffeeDAO->getAll();
$orders = unserialize($_SESSION["orders"]);

?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Triton Coffee Shop - Order Form</title>
        <style>
        </style>
    </head>

    <body>
        <h1>Triton Coffee Shop</h1>
        <h2>Enter Order <?php echo $name ?></h2>
        <form action="process_order.php" method="POST">
            <table>
                <tr>
                    <th>Product Name</th>
                    <th>Price</th>
                    <th>Quantity</th>
                </tr>
                <?php
                foreach($items as $prod) {
                    $n = $prod->getName();
                    $p = $prod->getPrice();
                    $id = $prod->getId();
                    if (isset($orders[$id])) {
                        $quantity = $orders[$id]->getQuantity();
                    } else {
                        $quantity = "";
                    }

                    $lne = <<<"FORM"
                        <tr>
                        <th>{$n}</th>
                        <td>{$p}</td>
                        <td><input type="number" min="0" name="{$id}" value="{$quantity}" size="2"></td>
                        </tr>
FORM;
                    echo $lne;
                }
                ?>
            </table>
            <input type="submit" value="Checkout">
        </form>
    </body>
</html>
