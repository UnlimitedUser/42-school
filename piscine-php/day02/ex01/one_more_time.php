#!/usr/bin/php
<?php

date_default_timezone_set('Europe/Paris');

if ($argc != 2)
    return;

if (!preg_match("/(^[L|l]undi|^[M|m]ardi|^[M|m]ercredi|^[J|j]eudi|^[V|v]endredi|^[S|s]amedi|^[D|d]imanche) ([0-9]{1,2}) ([J|j]anvier|[F|f][e|é]vrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]o[u|û]t|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d][e|é]cembre) [0-9]{4} [0-9]{2}:[0-9]{2}:[0-9]{2}$/", $argv[1]))
{
    echo "Wrong Format\n";
    return;
}

$date_parts = explode(' ', $argv[1]);
$date_parts[2] = preg_replace(array("/Janvier/", "/Fevrier/", "/Mars/", "/Avril/", "/Mai/", "/Juin/", "/Juillet/", "/Aout/", "/Septembre/", "/Octobre/", "/Novembre/", "/Decembre/"),
                        array("1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"), ucfirst($date_parts[2]));

$oth = explode(":", $date_parts[4]);
echo mktime($oth[0], $oth[1], $oth[2], $date_parts[2], $date_parts[1], $date_parts[3])."\n";

?>
