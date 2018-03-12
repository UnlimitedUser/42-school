<?php
	session_start();
	include('DB.class.php');
	$db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
    $con = $db->db;
	if ($_POST['submit'] == 'OK')
	{
		$b = array();

		if (!$_POST['passwd'] || !$_POST['login'])
		{
			$_SESSION['nul'] = true;
			header('Location: create.html');
			return 0;
		}
		if ($con)
		{
			$pst = $_POST['login'];
			$log = mysqli_query($con, "SELECT `login` FROM player WHERE login like '$pst'", MYSQLI_STORE_RESULT);
			if ($log){
				$logd = mysqli_fetch_array($log);
				if ($logd['login'] == $pst)
				{
					mysqli_close($con);
					$_SESSION['nul'] = true;
					header('Location: create.html');
				}
				else
				{
					$p = hash("ripemd160", $_POST['passwd']);
					mysqli_query($con,"INSERT INTO player (`login`, `passwd`) VALUES ('$pst', '$p');") ;
					mysqli_close($con);
					header('Location: index.php');
				}	
			}
			else
			{
				$p = hash("ripemd160", $_POST['passwd']);
				mysqli_query($con,"INSERT INTO player (`login`, `passwd`) VALUES ('$pst', '$p');") ;
				mysqli_close($con);
				header('Location: index.php');
				echo "Mysql error 404!" . PHP_EOL;
			}

		}
	}
	else 
	{
		echo "ERROR\n";
		mysqli_close($con);
		header('Location: index.php');
	}

?>