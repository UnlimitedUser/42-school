<?php
	session_start();
	include ('ship.class.php');
	include ('DB.class.php');
	if (isset($_GET['x']))
		$x = $_GET['x'];
	else
		$x = -1;
	if (isset($_GET['y']))
		$y = $_GET['y'];
	else
		$y = -1;
	$id = $_SESSION['id'];
	$db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
	if ($x != -1 && $y != -1)
		$db->query("update users set x = '$x', y = '$y' where id = '$id'");
?>