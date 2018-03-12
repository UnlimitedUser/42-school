<?php
	include ('DB.class.php');

	function auth($login, $passwd)
	{
		$db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
		$con = $db->db;
		$b = mysqli_query($con,"SELECT * FROM player WHERE login = '$login'", MYSQLI_STORE_RESULT);
		$data = mysqli_fetch_array($b, MYSQLI_ASSOC);
		if ($data['passwd'] == $passwd)
		{
			$db->query("UPDATE `player` SET `ships` = 1 where `login` = '$login'");
			mysqli_close($con);
			return true;
		}
		else
		{
			mysqli_close($con);
			return false;
		}
	}
?>