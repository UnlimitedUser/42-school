#!/usr/bin/php
<?php

if ($argc != 2 || !file_exists($argv[1]))
	return;

$str = file_get_contents($argv[1]);

$str = preg_replace_callback("/(title=)([\"'].*[\"'])/i", function ($s)
{
	return $s[1].strtoupper($s[2]);
}, $str);

$str = preg_replace_callback("/(<a .*?)(>.*?<)\/a>/is", function ($s)
{
	return $s[1].preg_replace_callback("/>(.*?)</is", function($t)
	{
		return ">".strtoupper($t[1])."<";
	}, $s[2])."/a>";
}, $str);

echo $str;

?>