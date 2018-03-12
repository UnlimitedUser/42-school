<?php
	session_start();
	include ('DB.class.php');

	$db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
	$arr = $db->fetch($db->query('select * from users where id = 1'));
	$arr2 = $db->fetch($db->query('select * from users where id = 2'));

	if ($_SESSION['id'] == 1)
	{
		$p = array('x1'=>$arr['x'], 'y1' => $arr['y'], 'x2' => $arr2['x'], 'y2' => $arr2['y']);
	}
	else
	{
		$p = array('x1'=>$arr2['x'], 'y1' => $arr2['y'], 'x2' => $arr['x'], 'y2' => $arr['y']);
	}

	echo json_encode($p);
?>