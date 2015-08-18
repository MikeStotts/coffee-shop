<?php
//TODO: write real validatin code
session_start();
extract($_POST);
foreach($_POST as $field => $value)
{
    if ($value != "")
    {
        if ($field == "name")
        {
            if (preg_match("/^[ .A-Za-z]{1,50}$/i", $value))
            {
                $good_data[$field] = $value;
            }
            else
            {
                $bad_data[] = $field;
                $error_msg[$field] = "Invalid name";
            }
        }

    }
    else
    {
        $bad_data[] = $field;
        $error_msg[$field] = "Required field";
    }
}
if (isset($bad_data)) {
    $message = "<ul>";
    foreach($bad_data as $field => $value) 
    {
        $message .= "<li>$value: {$error_msg[$value]}</li>";
    }
    $message .= "</ul>";
    include("register.inc");
    exit();
}
else
{
    $_SESSION["name"] = $name;
    include_once("User.inc");
    $u = User::newUser(0, $name, $pass, $fname, $lname, $address, $zip, $phone, $cc, $cctype);
    $u->addDB();
    include("order_form.inc");
    exit();
}
?>
