<html>
  <head>
    <link href="styles/main.css" rel="stylesheet" type="text/css"/>
  </head>
  <body>
    <center>
      <h1>Search</h1>
      <a href="proxy.php?F=public/main.php">Back to menu</a>
      <form name="search" method=get action="proxy.php">
        Pattern: <input type=text name="P"/>
        <input type='hidden' name='F' value='public/list.php'/>
      </form>
      <h1> Books list </h1>
      <table>
        <colgroup> <col width="90"/> <col width="60"/> </colgroup>
        <tr><th>Title</th><th>Price</th><th>ISBN</th></tr>
<?php
  connect_db();
  if (isset($_GET["P"])) {
    $sql = "SELECT title, price, isbn FROM books WHERE title LIKE '%";
    $sql .= $_GET["P"] . "%'";
  } else {
    $sql = "SELECT title, price, isbn FROM books";
  }
  $result = mysql_query($sql);
  for ($i = 0; $i < mysql_num_rows($result); $i += 1) {
    echo("<tr><td><a href='proxy.php?F=public/order.php&I=");
    echo(mysql_result($result, $i, 2) . "'>");
    echo(mysql_result($result, $i, 0) . "</a></td><td>");
    echo(mysql_result($result, $i, 1) . "&#8364;</td><td>");
    echo(mysql_result($result, $i, 2) . "</td></tr>\n");
  }
  mysql_close();
?>
      </table>
    </center>
  </body>
</html>
