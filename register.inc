<?php
/* Program: register.inc
 * Desription: Display custmoer rigistration form
 */
?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Register A New Account</title>
        <style>
            form input {display:block};
        </style>
    </head>

    <body>
        <h1>Triton Coffee Shop</h1>
        <h2>Enter New Account Info</h2>
        <?php
        if (isset($message)) {
            echo "<p>$message</p>";
        }
        ?>
        <form action="process_register.php" method="POST">
            <label>Name<input type="text" id="name" name="name" 
                value="<?php echo @$name ?>"></label>
            <label>Password<input type="password" id="pass" name="pass" 
                value="<?php echo @$pass ?>"></label>
            <label>Confirm Password<input type="password" id="cpass" name="cpass" 
                value="<?php echo @$cpass ?>"></label>
            <label>First Name<input type="text" id="fname" name="fname" 
                value="<?php echo @$fname ?>"></label>
            <label>Last Name<input type="text" id="lname" name="lname" 
                value="<?php echo @$lname ?>"></label>
            <label>Address<input type="text" id="address" name="address" 
                value="<?php echo  @$address ?>"></label>
            <label>ZIP<input type="text" id="zip" name="zip" 
                value="<?php echo @$zip ?>"></label>
            <label>Phone<input type="text" id="phone" name="phone" 
                value="<?php echo @$phone ?>"></label>
            <label>Credit Card<input type="text" id="cc" name="cc" 
                value="<?php echo @$cc ?>"></label>
            <label>Credit Card Type<input type="text" id="cctype" name="cctype" 
                value="<?php echo @$cc_type ?>"></label>
            <input type="submit" id="submit" value="Register">
        </form>
    </body>
</html>
