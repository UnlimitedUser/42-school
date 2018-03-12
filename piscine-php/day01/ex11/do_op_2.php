#!/usr/bin/php
<?php

function get_op($argv)
{
    if (strstr($argv[1], "*"))
        return '*';
    if (strstr($argv[1], "-"))
        return '-';
    if (strstr($argv[1], "+"))
        return '+';
    if (strstr($argv[1], "/"))
        return '/';
    if (strstr($argv[1], "%"))
        return '%';
    return "incorrect";
}

if ($argc != 2)
{
    echo "Incorrect Parameters\n";
    exit ;
}

$op = trim(get_op($argv));
$argv[1] = str_replace(['+', '-', '*', '/', '%'], "+", $argv[1]);
$arr = explode("+", $argv[1]);

if (count($arr) != 2)
{
    echo "Syntax Error\n";
    exit ;
}

$t1 = trim($arr[0]);
$t2 = trim($arr[1]);

if (!ctype_digit($t1) || !ctype_digit($t2))
{
    echo "Syntax Error\n";
    exit ;
}

switch ($op)
{
    case '+':
        echo $t1 + $t2, "\n";
        break;
    case '-':
        echo $t1 - $t2, "\n";
        break;
    case '/':
        if ($t2 === '0')
        {
            echo "Incorrect Parameters\n";
            exit;
        }
        echo $t1 / $t2, "\n";
        break;
    case '*':
        echo $t1 * $t2, "\n";
        break;
    case '%':
        echo $t1 % $t2, "\n";
        break;
    default:
        echo "Syntax Error\n";
        break;
}

?>
