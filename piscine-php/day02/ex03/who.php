#!/usr/bin/php
<?php

date_default_timezone_set('Europe/Bucharest');
$file = fopen("/var/run/utmpx", "r");
if ($file == NULL)
{
	echo "Failed opening utmpx file\n";
	exit(1);
}
while ($utmpx = fread($file, 628))
{
	$array = unpack("a256user/a4num/a32term/iD/iE/I2time", $utmpx);
	$data[$array['term']] = $array;
}
ksort($data);
foreach ($data as $val)
{
	if ($val['E'] == 7)
	{
		echo $val['user'] . " ";
		echo $val['term'] . "  ";
		echo date("M  j", $val['time1']) . " ";
		echo date("H:i", $val['time1']) . "\n";
	}
}

?>