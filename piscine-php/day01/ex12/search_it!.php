#!/usr/bin/php
<?php

if ($argc <= 2)
    exit;

$arr = array();

for ($a = 2; $a < $argc; $a++)
{
    $parts = explode(":", $argv[$a]);
    if (isset($parts[1]))
        $arr[$parts[0]] = $parts[1];
}

if (isset($arr[$argv[1]]))
    echo $arr[$argv[1]]."\n";

?>
