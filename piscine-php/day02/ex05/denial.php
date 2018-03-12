#!/usr/bin/php
<?php

    date_default_timezone_set("UTC");
    ini_set("display_startup_errors", 1);
    ini_set("display_errors", 1);
    error_reporting(E_ERROR | E_WARNING | E_PARSE);
    if ($argc != 3)
        exit();
    if (!file_exists($argv[1]))
        exit(1);
    $read = fopen($argv[1], 'r');
    $ar = array();
    $bin = array("last_name","surname","login","IP","pseudo");
    $surname = array();
    $last_name = array();
    $login = array();
    $IP = array();
    $pseudo = array();
    $name = array();
   $ar = array();
    while ($read && !feof($read))
     {
        $str = fgets($read);
        if ($str === false)
            break;
        $ar = explode(";", trim($str));
        print_r($ar);
        $surname[$ar[array_search($argv[2],$bin)]] = $ar[1];
        $name[$ar[array_search($argv[2],$bin)]] = $ar[1];
        $last_name[$ar[array_search($argv[2],$bin)]] = $ar[0];
        $login[$ar[array_search($argv[2],$bin)]] = $ar[2];
        $IP[$ar[array_search($argv[2],$bin)]] = $ar[3];
        $pseudo[$ar[array_search($argv[2],$bin)]] = $ar[4];
    }
    $stdin = fopen("php://stdin", "r");
    while ($stdin && !feof($stdin)) {
        echo "Entrez votre commande: ";
        $order = fgets($stdin);
       
       eval($order);
        }
     fclose($stdin);
    echo "\n";

?>