<?php
$srv = "http://localhost/~web/private/proxy.php";
$unqlite_jx9 = "/usr/local/bin/unqlite_jx9";
$unqlite_db = "/home/web/public_html/system/db";
function connect_db() {                                                         
  $db_host = "localhost";                                                       
  $db_user = "ressi_user";                                                      
  $db_pass = "ressi_pwd";                                                       
  $db_base = "ressi_db";                                                        
  $db = mysql_connect($db_host, $db_user, $db_pass, $db_base);                  
  if (! $db) {                                                                  
    die("Can't connect to mysql.");                                             
  } else {                                                                      
    $err = mysql_select_db("$db_base", $db);                                    
    if (! $err) {                                                               
      die("Can't connect to database.");                                        
    }                                                                           
  }                                                                             
}
?>
