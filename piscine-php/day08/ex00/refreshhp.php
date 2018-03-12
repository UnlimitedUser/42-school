<?php
	session_start();
	include("ship.class.php");
	include("DB.class.php");
	$db = new db(["10.21.0.96", "root", "bitnami", "battleship"]);
	$arr = $db->fetch($db->query('select * from users where id = 1;'));
	$arr2 = $db->fetch($db->query('select * from users where id = 2;'));	
	if ($_SESSION['id'] == 1)
		$p = array('myhp'=>$arr['HP'], 'hishp' => $arr2['HP']);
	else
		$p = array('myhp'=>$arr2['HP'], 'hishp' => $arr['HP']);
	echo json_encode($p);
?>