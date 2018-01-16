<html>
  <head>
    <link href="styles/main.css" rel="stylesheet" type="text/css"/>
  </head>
  <head>
    <script>
function bill() {
  var I = document.getElementById("I").value;
  var C = document.getElementById("C").value;
  var Q = document.getElementById("Q").value;
  var T = new Number(document.getElementById("Q").value) *
          new Number(document.getElementById("P").value);
  var L = "proxy.php?F=public/bill.php&I=" + I + "&Q=" + Q + "&T=" + T + "&C=" + C;
  document.documentURI = L;
  document.location = L;
}
    </script>
  </head>
  <body>
    <center>
      <h1>Order a book</h1>
      <a href="proxy.php?F=public/main.php">Back to menu</a>
<?php
  connect_db();
  $sql = "SELECT title, price, isbn FROM books WHERE isbn = '";
  $sql .= $_GET["I"] . "'";
  $result = mysql_query($sql);
?>
      <form name='order' method=get action='javascript:bill()'>
        <table>
          <tr>
            <td>Title</td>
            <td><input type=text name='T' value='<?php echo mysql_result($result, $i, 0); ?>' readonly/></td>
          </tr>
          <tr>
            <td>ISBN (10 digits)</td>
            <td><input type=text id="I" name='I' value='<?php echo mysql_result($result, $i, 2); ?>' readonly/></td>
          </tr>
          <tr>
            <td>Price</td>
            <td><input type=text id="P" name='P' value='<?php echo mysql_result($result, $i, 1); ?>' readonly/></td>
          </tr>
          <tr>
            <td>Quantity</td>
            <td><input type=text id="Q" name='Q' value='1'/></td>
          </tr>
          <tr>
            <td>Card # (8 digits)</td>
            <td><input type=text id="C" name='C'/></td>
          </tr>
        </table>
        <input class="btn" type='submit' value='Order'/>
      </form>
<?php
  mysql_close();
?>
    </center>
  </body>
</html>
