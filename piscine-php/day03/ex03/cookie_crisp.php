<?php

if ($_GET['action'] = "set")
	setcookie($_GET['name'], $_GET['value']);
else if ($_GET['action'] == "get")
{
	$cookie = $_COOKIE[$_GET['name']];
	if ($cookie)
	echo $cookie."\n";
}
else if ($_GET['action'] == "del")
	setcookie($_GET['name'], "", 1);

?>
