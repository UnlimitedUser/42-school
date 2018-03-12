<?php

function ft_is_sort($arr)
{
    $a = $arr;
    sort($a);
    return ($arr === $a);
}

?>
