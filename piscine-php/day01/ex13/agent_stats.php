#!/usr/bin/php
<?php

if ($argc != 2)
	return;

if (!($line = fgets(STDIN)))
	return;

$total = 0;
$c = 0;	
$usr = array();

if ($argv[1] === 'moyenne')
	while ($line = fgets(STDIN))
	{
		$arr = str_getcsv($line, ';');
		if ($arr[2] !== "moulinette" && $arr[1] !== '')
		{
			$total += $arr[1];
			$c++;
		}
	}
elseif ($argv[1] === 'moyenne_user' || $argv[1] === 'ecart_moulinette')
{
	while ($line = fgets(STDIN))
	{
		$arr = str_getcsv($line, ';');
		if ($arr[1] !== '' && $arr[2] !== "moulinette")
		{
			$usr[$arr[0]]['total'] += $arr[1];
			$usr[$arr[0]]['index']++;
		}
		else if ($arr[2] === 'moulinette')
			$usr[$arr[0]]['moulinette'] = $arr[1];
	}
}
else
	return;

ksort($usr);

if ($argv[1] === 'moyenne')
	echo ($total / $c)."\n";
elseif ($argv[1] === 'moyenne_user')
	foreach ($usr as $k => $v)
		echo $k . ":" . ($v['total'] / $v['index'])."\n";
else
	foreach ($usr as $k => $v)
		echo $k . ":" . (($v['total'] / $v['index']) - $v['moulinette'])."\n";

?>
