#!/usr/bin/php
<?php

$str = "";

for ($a = 1; $a < $argc; $a++)
	$str .= "$argv[$a] ";

$arr = explode(" ", $str);
sort($arr);
unset($arr[0]);

if ($argc > 1)
	echo implode("\n", $arr)."\n";

?>
