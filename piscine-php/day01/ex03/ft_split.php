<?php

function ft_split($s)
{
	$arr = preg_split("/\s+/", $s);
	sort($arr);
	return $arr;
}

?>
