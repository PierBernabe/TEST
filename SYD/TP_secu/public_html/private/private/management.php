<html>
  <head>
    <link href="styles/main.css" rel="stylesheet" type="text/css"/>
  </head>
  <body>
    <center>
      <h1>System update</h1>
      <form action="proxy.php" method="get">
        <input type="hidden" name="F" value="private/management.php"/>
        <input type="hidden" name="G" value="update"/>
        <table>
          <tr><td>Key:</td><td><input type='text' name='K'/></td></tr>
          <tr><td>Old value:</td><td><input type='text' name='O'/></td></tr>
          <tr><td>New value:</td><td><input type='text' name='N'/></td></tr>
        </table>
        <input class="btn" type='submit' value='update'/>
      </form>
<?php
  include("../inc.php");
  if (isset($_GET["G"]) and $_GET["G"] === "update"
      and isset($_GET["O"]) and isset($_GET["N"]) and isset($_GET["K"])) {

    $tmpfname = tempnam("/tmp", "SCRIPT");
    $handle = fopen($tmpfname, "w");
    $script = '
        $collection = \'config\';
        $zCallback = function($rec) {
          if ($rec.key == \'%s\' && $rec.value == \'%s\') {
            return TRUE;
          }
          return FALSE;
        };
        $tmp = db_fetch_all($collection, $zCallback);
        if ($tmp && count($tmp) == 1) {
          $row = array_pop($tmp);
          if ($row) {
            db_drop_record($collection, $row.__id);
            $row.value = \'%s\';
            db_store($collection, $row);
            print "<h2>Property updated!</h2>";
          } else {
            print "<h2 class=\'err-msg\'>Invalid key or old value</h2>";
          }
        } else {
          print "<h2 class=\'err-msg\'>Invalid key or old value</h2>";
        }';
    $script = sprintf($script, $_GET["K"], $_GET["O"], $_GET["N"]);
    fwrite($handle, $script);
    fclose($handle);
    system("$unqlite_jx9 $unqlite_db $tmpfname");
    unlink($tmpfname);
  }
?>
    </center>
  </body>
<html>
