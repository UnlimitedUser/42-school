<?php 

function auth($login, $passwd)
{
	$passwd = hash("whirlpool", $passwd);
	if ($str = unserialize(file_get_contents("../private/passwd")))
		foreach ($str as $val)
			if ($val['login'] === $login && $val['passwd'] === hash("whirlpool", $passwd))
				return true;
	return false;
}

?>