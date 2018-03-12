<?php
	session_start();
	include("auth.php");
	$db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
	$r = $db->fetch($db->query("select count(*) from player group by ships;"));
	$l = $_POST['login'];
	$p = hash("ripemd160", $_POST['passwd']);
	if ($r == 2)
	{
		header('Location: index.php?err=1');
	}
	if (auth($l, $p) == true)
	{
		$id = $db->fetch($db->query("select id from player where login = '$l'"));
		$_SESSION["loggued_on_user"] = $l;
		$_SESSION['logedin'] = true;
		header('Location: main.php?id='.$id['id']);
	}
	else 
	{
		$_SESSION["loggued_on_user"] = $l;
		header('Location: index.php');
	}
?>