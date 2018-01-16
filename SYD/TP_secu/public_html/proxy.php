<?php
include("inc.php");
if (isset($_COOKIE["SESSION"])) {
  session_id($_COOKIE["SESSION"]);
  session_start();
  setcookie("SESSION", $_COOKIE["SESSION"], time() + 3600);
  if (isset($_SESSION['id'])) {
    if (isset($_GET["F"]) and ! (preg_match("/\.\./", $_GET["F"]))
        and (substr($_GET["F"], 0, strlen("private/")) !== "private/"
            or ($_SESSION['id'] == 1)
                and $_GET["F"] === "private/management.php")) {
      if ($_GET["F"] === "private/management.php") {
        $g = isset($_GET["G"]) ? "&G=" . $_GET["G"] : "";
        $k = isset($_GET["K"]) ? "&K=" . $_GET["K"] : "";
        $n = isset($_GET["N"]) ? "&N=" . $_GET["N"] : "";
        $o = isset($_GET["O"]) ? "&O=" . $_GET["O"] : "";
        $url = $srv . "?X=" . $_GET["F"] . $g . $k . $n . $o;
        print(file_get_contents($url, false));
      } else {
        include($_GET["F"]);
      }
    } else {
      include('public/fun-err.php');
    }
  } else {
    header('Location: login-err.html');
  }
} else {
  header('Location: login-err.html');
}
?>
