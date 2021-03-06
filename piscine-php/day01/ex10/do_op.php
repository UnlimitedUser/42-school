#!/usr/bin/php
<?php

if ($argc != 4)
{
    echo "Incorrect Parameters\n";
    exit ;
}
$argv[1] = trim($argv[1]);
$argv[2] = trim($argv[2]);
$argv[3] = trim($argv[3]);
switch ($argv[2])
{
    case '+':
        echo $argv[1] + $argv[3], "\n";
        break;
    case '-':
        echo $argv[1] - $argv[3], "\n";
        break;
    case '/':
        if ($argv[3] === '0')
        {
            echo "Incorrect Parameters\n";
            exit ;
        }
        echo $argv[1] / $argv[3], "\n";
        break;
    case '*':
        echo $argv[1] * $argv[3], "\n";
        break;
    case '%':
        echo $argv[1] % $argv[3], "\n";
        break;
}

?>
