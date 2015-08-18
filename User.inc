<?php
//TODO: Hash user password
//TODO: getters/setters
//TODO: Refactor to a POJO for use with DAO
class User {
    private $customer_id = "";
    private $username = "";
    private $password = "";
    private $first = "";
    private $last = "";
    private $address = ""; 
    private $zip = "";
    private $phone = "";
    private $cc = "";
    private $cc_type = "";

    static function newUser($id, $name, $pass, $first, $last, $address, $zip, $phone, $cc, $cct)
    {
        $u = new User;
        $u->customer_id = $id;
        $u->username = $name;
        $u->password = $pass;
        $u->first = $first;
        $u->last = $last;
        $u->address = $address;
        $u->zip = $zip;
        $u->phone = $phone;
        $u->cc = $cc;
        $u->cc_type = $cct;
        return $u;
    }

    static function getUser($name) {
        include("dbstuff.inc");
        $cxn = mysqli_connect($host,$user,$password,$database)
            or die ("couldn't connect to server");
        $query = "SELECT * FROM mlsn87_users 
            WHERE username='$name'";
        $result = mysqli_query($cxn,$query)
            or die ("Couldn't execute query.");
        $row = mysqli_fetch_assoc($result);
        $u = new User();
        $u->customer_id = $row["customer_id"];
        $u->username = $row["username"];
        $u->password = $row["password"];
        $u->first = $row["first"];
        $u->last = $row["last"];
        $u->address = $row["address"];
        $u->zip = $row["zip"];
        $u->phone = $row["phone"];
        $u->cc = $row["cc"];
        $u->cc_type = $row["cc_type"];
        return $u;
    }

    // Are name and password correct.
    static function verify($name, $pass) {
        include("dbstuff.inc");
        $cxn = mysqli_connect($host, $user, $password, $database)
            or die("Couldn't connect to server");
        $query = $cxn->prepare("SELECT username FROM mlsn87_users
            WHERE username=? AND password=?");
        $query->bind_param("ss", $name, $pass);

        $query->execute()
            or die("couldn't verify user: " . mysqli_error($cxn));
        $result = $query->get_result();
        $n_rows = $result->num_rows;
        $query->close();
        $cxn->close();
        return $n_rows > 0;
    }

    // Does name already exist
    static function validate($user) {
        include("dbstuff.inc");
        $cxn = mysqli_connect($host, $user, $password, $database)
            or die("Couldn't connect to server");
        $query = "SELECT username FROM mlsn87_users
            WHERE username='$user'";
        $result = mysqli_query($cxn,$query)
            or die("couldn't validate user: " . mysqli_error($cxn));
        $n_row = mysqli_num_rows($result);
        var_dump($n_row);
        return $n_row >= 1;
    }

    function addDB()
    {
        include("dbstuff.inc");
        $cxn = mysqli_connect($host,$user,$password,$database)
            or die ("couldn't connect to server: " . mysqli_error($cxn));
        $query = "INSERT INTO mlsn87_users 
                     VALUES ('$this->customer_id',
                             '$this->username',
                             '$this->password',
                             '$this->first',
                             '$this->last',
                             '$this->address',
                             '$this->zip',
                             '$this->phone',
                             '$this->cc',
                             '$this->cc_type'
                    )";
        $result = mysqli_query($cxn, $query)
            or die("couldn't add user: " . mysqli_error($cxn));
    }

    function updateDB() 
    {
    }

    function getCustomer_id()
    {
        return $this->customer_id;
    }

    function setCustomer_id($id)
    {
        $this->customer_id = $id;
    }

    function getUsername()
    {
        return $this->username;
    }

    function setUsername($name)
    {
        $this->username = $name;
    }

    function getPassword()
    {
        return $this->password;
    }

    function setPassword($pass)
    {
        $this->password = $pass;
    }

    function getFirst()
    {
        return $this->first;
    }

    function setFirst($name)
    {
        $this->first = $name;
    }

    function getLast()
    {
        return $this->last;
    }

    function setLast($name)
    {
        $this->last = $name;
    }

    function getAddress()
    {
        return $this->address;
    }

    function setAddress($addr)
    {
        $this->address = $addr;
    }

    function getZip()
    {
        return $this->zip;
    }

    function setZip($z)
    {
        $this->zip = $z;
    }

    function getPhone()
    {
        return $this->phone;

    }

    function setPhone($p)
    {
        $this->phone = $p;
    }

    function getCC()
    {
        return $this->cc;

    }

    function setCC($c)
    {
        $this->cc = $c;
    }

    function getCC_type()
    {
        return $this->cc_type;

    }

    function setCC_type($c)
    {
        $this->cc_type = $c;
    }

}


