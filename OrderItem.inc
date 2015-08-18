<?php
class OrderItem {
    private $coffee; 
    private $quantity;
    private $orderId;

    function __construct($coffee, $quantity)
    {
        $this->coffee = $coffee;
        $this->quantity = $quantity;
    }

    function setQuantity($i)
    {
        $this->quantity = $i;
    }

    function getQuantity()
    {
        return $this->quantity;
    }

    function getCoffee() {
        return $this->coffee;
    }

    function getId() {
        return $this->coffee->getId();
    }

    function getName() {
        return $this->coffee->getName();
    }

    function getPrice() {
        return $this->coffee->getPrice();
    }

    function getCost() {
        return $this->coffee->getPrice() * $this->quantity;
    }

    function setOrderId($orderId) {
        $this->orderId = $orderId;
    }

    function getOrderId() {
        return $this->orderId;
    }
}
?>
