<?php

$str = file_get_contents("list.csv");

$exp = explode("\n", $str);

foreach ($exp as $key => $value)
	if ($value === $_GET['todo'])
		unset($exp[$key]);

file_put_contents("list.csv", implode("\n", $exp));

?>