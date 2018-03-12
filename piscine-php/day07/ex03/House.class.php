<?php

abstract class House
{
	abstract function getHouseName();
	abstract function getHouseMotto();
	abstract function getHouseSeat();

	function introduce()
	{
		echo "House ".getHouseName()." of ".getHouseSeat()." : \"".getHouseMotto()."\"".PHP_EOL;
	}
}

?>