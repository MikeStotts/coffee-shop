<?php
require_once("OrderDAO.inc");
require_once("OrderItemDAOMySQL.inc");
require_once("OrderItem.inc");
require_once("MySQL.inc");

class OrderDAOMySQL implements OrderDAO {
    //TODO: Write getAll
    function getAll() {
    }
    
    //TODO: Write get
    function get(int $id) {
    }
    
    //TODO: Write update 
    function update($order) {
    }
    
    //TODO: Write delete
    function delete($order) {
    }
    
    //TODO: Write add 
    function add(Order $order) {
        $cust = $order->getCustomer();
        $cust_id = $cust->getCustomer_id();
        $mysql = new MySQL();
        $query = "insert into mlsn87_orders values (" .
            "'0'," .
            "'". date("Y-m-d") . "'," .
            "'{$cust_id}'," .
            "'{$order->getTotal()}')";
        $result = $mysql->query($query);
        $order->setInvoice($mysql->getLastInsert());
        //TODO: write OrderItems to db.
        $orderItemDAO = new OrderItemDAOMySQL();
        foreach ($order as $itemId => $item) {
            $orderItemDAO->add($order, $item);            
        }
    }
}
?>
