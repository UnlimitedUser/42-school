#!/usr/bin/php
<?php

if ($argc == 1)
    exit;

$str = preg_replace("/[ ]+/", " ", trim($argv[1]));

$arr = explode(" ", $str);

for ($a = 1, $s = count($arr); $a < $s; $a++)
    echo $arr[$a]." ";
echo $arr[0]."\n";

?>
