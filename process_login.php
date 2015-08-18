<?php
session_start();
foreach ($_POST as $field => $value)
{
    $_SESSION[$field] = strip_tags(trim($value));
}
//FIXME: use of extract bad practice (security)
extract($_POST);
// check if user registered
require_once("UserDAOMySQL.inc");
$userDAO = new UserDAOMySQL();
$user = $userDAO->get($name);
if($user != null && $user->getPassword() == $pass) // if login successful
{
    $_SESSION["user"] = serialize($user);
    $_SESSION["auth"] = "yes";
    include("order_form.inc");
    exit();
}
else
{
    $message = "Invalid login";
    include("login.inc"); // if not validated
    exit();
}
?>
