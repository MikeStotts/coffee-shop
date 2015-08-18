<?php
#include_once("CoffeeCollection.inc");
#$collection = new CoffeeCollection();
if ($_SESSION["auth"] != "yes")
{
    $_SESSION["logon_message"] = "Log in before ordering";
    include("logon.inc");
    exit();
}
?>
<!DOCTYPE hmtl>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <title>Triton Coffee Shop - Checking Out</title>
    </head>
    <body>
        <h1>Triton Coffee Shop - Check Out</h1>
        <h2>Checking Out</h2>
        <?php
            $orders = unserialize($_SESSION["orders"]);
            $user = $orders->getCustomer();
            $first = $user->getFirst();
            $last = $user->getLast();
            $addr = $user->getAddress();
            $zip = $user->getZip();
            $cc = $user->getCC();
            $cc_type = $user->getCC_type();

            echo $first . " " . $last . "<br />" .
                $addr . "<br />" .
                $zip . "<br />" .
                $cc_type . " - " . $cc . "<br />";
        ?>
        <table>
        <tr>
        <th>Description</th>
        <th>Price</th>
        <th>Quantitiy</th>
        <th>Cost</th>
        </tr>
        <?php
            foreach($orders as $prod => $item) {
                $quantity = $item->getQuantity();
                if ($quantity > 0) {
                    $desc = $item->getName();
                    $price = $item->getPrice();
                    $cost = $item->getCost();
                    $lne = 
                        "<tr>" .
                            "<td>$desc</td>" .
                            "<td>$price</td>" .
                            "<td>$quantity</td>" .
                            "<td>$cost</td>" .
                        "</tr>";
                    echo $lne;
                }
           }
        ?>
        </table>
        <p>Total cost <?php echo $orders->getTotal(); ?></p>
        <form action="process_checkout.php" method="POST">
            <input type="submit" value="Finished">
        </form>
        <form action="loggedin.php" method="POST">
            <input type="submit" value="Change order">
        </form>
    </body>
</html>
