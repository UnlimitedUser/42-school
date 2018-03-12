<?php
	include ('ship.class.php');
	include ('DB.class.php');
	session_start();
	$id = $_SESSION['id'];
	if ($id == 1)
		$id = 2;
	else
		$id = 1;
	$db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
	$db->query("update users set HP = HP - 1 where id = '$id'");
?>