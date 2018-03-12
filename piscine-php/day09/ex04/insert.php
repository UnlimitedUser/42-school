<?php

$str = file_get_contents("lst.csv");

$n = 0;

$n = substr_count("str", "\n");

file_put_contents("list.csv", $n . $_GET['todo'] . "\n", FILE_APPEND | LOCK_EX);

?>