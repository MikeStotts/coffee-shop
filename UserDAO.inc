<?php

require_once("User.inc");

interface UserDAO {
    function getAll();
    function get($name);
    function update(User $user);
    function delete(User $user);
    function add(User $user);
}

?>
