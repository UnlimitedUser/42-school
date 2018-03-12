<?php

if ($_POST['login'] !== "" && $_POST['passwd'] !== "" && $_POST['submit'] === 'OK')
{
	if (!file_exists("../private"))
	{
		mkdir("../private");
		file_put_contents("../private/passwd", null);
	}
	$file = unserialize(file_get_contents("../private/passwd"));
	if ($file)
		foreach ($file as $f)
		{
			if ($f['login'] === $_POST['login'])
			{
				echo "ERROR\n";
				exit;
			}
		}
	$file[] = array('login' => $_POST['login'], 'passwd' => hash("whirlpool", $_POST['passwd']));
	file_put_contents("../private/passwd", serialize($file));
	echo "OK\n";
}
else
	echo "ERROR\n";

?>