<?php
require_once("OrderItemDAO.inc");
class OrderItemDAOMySQL implements OrderItemDAO {
    //TODO: Write getAll
    function getAll() {
    }
    
    //TODO: Write get
    function get(int $id) {
    }
    
    //TODO: Write update 
    function update(OrderItem $item) {
    }
    
    //TODO: Write delete
    function delete(OrderItem $item) {
    }
    
    //TODO: Write add 
    function add(Order $order, OrderItem $item) {
        include("dbstuff.inc");
        $cxn = mysqli_connect($host, $user, $password, $database)
            or die("Couldn't connect to server");
        // FIXME: refactor to use prepared statement
        $query = "insert into mlsn87_order_items values (" .
                "'0'," .
                "'" . $order->getInvoice() . "'," .
                "'" . $item->getId() . "'," .
                "'" . $item->getQuantity() . "')";
        $result = mysqli_query($cxn, $query);
        $cxn->close();
    }
}
?>
