<?php
class Order implements Iterator, ArrayAccess {
    private $invoice = 0;
    private $products = array();
    private $customer;
    private $total = 0;

    function __construct($cust)
    {
        $this->customer = $cust;

    }

    function addItem($item) {
        $id = $item->getId();
        $this->products[$id] = $item;
    }       
    
    function rmItem($item) {
        $id = $item->getId();
        unset($this->products[$id]);
    }
    
    function getInvoice() {
        return $this->invoice;
    }

    function setInvoice($invoice) {
        $this->invoice = $invoice;
    }

    function getCustomer() {
        return $this->customer;
    }
    
    function setCustomer($customer) {
        $this->customer = $customer;
    }

    function getProducts() {
        return $this->products;
    }

    function setTotal($total) {
        $this->total = $total;
    }

    function getTotal() {
        return $this->total;
    }

    function current() {
        return current($this->products);
    }

    function key() {
        return key($this->products);
    }

    function next() {
        next($this->products);
    }

    function rewind() {
        reset($this->products);
    }

    function valid() {
        return current($this->products) !== false;
    }

    function offsetExists($offset) {
        return isset($this->products[$offset]);
    }

    function offsetGet($offset) {
        return isset($this->products[$offset]) ? $this->products[$offset] : null;
    }

    function offsetSet($offeet, $value) {
        if (is_null($offset)) {
            $this->products[] = $value;
        } else {
            $this->products[$offet] = $value;
        }
    }

    function offsetUnset($offset) {
        unset($this->product[$offset]);
    }
}
?>
