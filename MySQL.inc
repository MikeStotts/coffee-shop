<?php
class MySQL {
    private $cnx = null;

    function __construct() {
        include("dbstuff.inc");
        $this->cnx = mysqli_connect($host, $user, $password, $database)
            or die("Couldn't connect to server");
    }

    //TODO: write query
    function query($query) {
        return $this->cnx->query($query);
    }

    //TODO: write getLastInsert 
        function getLastInsert() {
            return $this->cnx->insert_id; 
    }
}    
?>
