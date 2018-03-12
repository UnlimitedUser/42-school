#!/usr/bin/php
<?php
echo "Enter a number: ";
while ($line = fgets(STDIN))
{
	$line = str_replace("\n", "", $line);
	if (is_numeric($line))
		echo "The number $line is ".($line % 2 == 0 ? "even" : "odd")."\n";
	else
		echo "'$line' is not a number\n";
	echo "Enter a number: ";
}
?>
