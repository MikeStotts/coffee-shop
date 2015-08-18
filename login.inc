<?php
/* Program name: login.inc
 * Decription: Display a form that collects a users name and password
 * 
 */
?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <link href="index.css" rel="stylesheet">
        <title>Coffee Shop Entrance</title>
    </head>
    <body>
        <!-- logon form -->
        <h1>Triton Coffee Shop</h1>
            <h2>Login</h2>
            <?php
            if (isset($message)) {
                echo "<p> $message </p>";
            }
            ?>
            <form action="process_login.php" method="POST">
                <label>Name <input type="text" id="name" name="name" 
                    value="<?php echo @$name ?>"></label>
                <label>Password<input type="password" id="pass"  name="pass"></label>
                <input type="hidden" name="sent" value="yes">
                <input type="submit" value="Login">
            </form>
            <!-- register form -->
            <form action="register.php">
                <input type="submit" value="Register Account" />
            </form>
    </body>
</html>
