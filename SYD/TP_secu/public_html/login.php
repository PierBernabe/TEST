<?php
include("inc.php");
$log_err = 1;
if (isset($_GET["L"]) and isset($_GET["P"])) {
  connect_db();
  $sql = "SELECT id, login FROM users WHERE login = '" . $_GET["L"] .
         "' AND password = '" . $_GET["P"] . "'";
  $result = mysql_query($sql);
  if (mysql_num_rows($result) != 0) {
    srand(time());
    $hex = "";
    $i = 0;
    while ($i < 2) {
      $r = rand();
      $hex .= sprintf("%08x%08x", rand() ^ ($r >> 16), rand() ^ ($r & 0xffff));
      $i = $i + 1;
    }
    $session = $hex;
    session_id($session);
    session_start();
    setcookie("SESSION", $session, time() + 3600);
    $_SESSION['id'] = mysql_result($result, 0, 0);
    $_SESSION['login'] = mysql_result($result, 0, 1);
    header('Location: proxy.php?F=public/main.php');
    $log_err = 0;
  }
}
if ($log_err == 1) {
  if (isset($_COOKIE["SESSION"])) {
    session_id($_COOKIE["SESSION"]);
    session_start();
    session_destroy();
  }
  header('Location: login-err.html');
}
?>
