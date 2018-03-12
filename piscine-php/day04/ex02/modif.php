<?php

if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['submit'] === 'OK' && ($file = unserialize(file_get_contents("../private/passwd"))))
{
	$change = false;
	foreach ($file as $k => $f)
	{
		if ($f['login'] === $_POST['login'] && $f['passwd'] === hash("whirlpool", $_POST['oldpw']))
		{
			$file[$k]['passwd'] = hash("whirlpool", $_POST['newpw']);
			$change = true;
		}
	}
	if (!$change)
		echo "ERROR\n";
	else
	{
		file_put_contents("../private/passwd", serialize($file));
		echo "OK\n";
	}
}
else
	echo "ERROR\n";

?>