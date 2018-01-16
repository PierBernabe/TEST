<?php
$a = isset($_GET["A"]) ? $_GET["A"] : "";
$c = isset($_GET["C"]) ? $_GET["C"] : "";
$p = isset($_GET["P"]) ? $_GET["P"] : "";
$f = ($a === "upload" and isset($_FILES["F"]["tmp_name"])) ?
     $_FILES["F"]["tmp_name"] : "";
$output = shell_exec('forum/forum.py ' .
  escapeshellarg($a) . ' ' . escapeshellarg($c) . ' ' .
  escapeshellarg($p) . ' ' . escapeshellarg($f));
echo $output;
?>
