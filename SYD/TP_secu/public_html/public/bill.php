<html>
  <head>
    <link href="styles/main.css" rel="stylesheet" type="text/css"/>
  </head>
  <body>
    <center>
      <h1>Order information</h1>
      <a href="proxy.php?F=public/main.php">Back to menu</a><br/>
<?php
  connect_db();
  $i = $_GET["I"];
  $q = $_GET["Q"];
  $t = $_GET["T"];
  $c = $_GET["C"];
  $sql = "SELECT title FROM books WHERE isbn = '" . $i . "'";
  $info = mysql_query($sql);
  mysql_close();
  print("Title: " . mysql_result($info, 0, 0) . "<br/>");
  print("Quantity: " . $q . "<br/>");
  print("Price: " . $t . "<br/>");
  $command="system/check_CB ". $i . " " . $q . " " . $t . " " . $c;
  system($command);
?>
    </center>
  </body>
</html>
