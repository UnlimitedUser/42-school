#!/usr/bin/php
<?php

if ($argc != 2)
    exit();
if (!file_exists($argv[1]))
    exit(1);

$read = fopen($argv[1], 'r');

$arr = array();

while (true)
{
	fgets($read);
	$str = fgets($read);
	$str = str_replace("\n", "", $str);
	$arr[] = explode(' --> ', $str);
	$s[$str] = fgets($read);
	if (!fgets($read))
		break;
}

sort($arr);

for ($i = 1, $count = count($arr); $i <= $count; $i++)
{
	echo "$i\n";
	echo $arr[$i - 1][0]." --> ".$arr[$i - 1][1]."\n";
	echo $s[$arr[$i - 1][0]." --> ".$arr[$i - 1][1]];
	if ($i < $count)
		echo "\n";
}

?>