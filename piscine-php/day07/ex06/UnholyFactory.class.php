<?php

class UnholyFactory
{
	private $soldiers;

	function __construct()
	{
		$soldiers = new array();
	}

	function absorb($sold)
	{
		if ($sold instanceof Fighter)
		{
			if (isset($soldiers[$sold->getName]))
				print("(Factory already absorbed a fighter of type " . $sold->getName() . ")" . PHP_EOL);
			else
			{
				print("(Factory absorbed a fighter of type " . $sold->getName() . ")" . PHP_EOL);
                $this->soldat[$sold->getName()] = $sold;
            }
		}
		else
	        print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
	}

	function fabricate($s)
	{
		if (isset($soldiers[$s]))
		{
			print("(Factory fabricates a fighter of type " . $s . ")" . PHP_EOL);
			return ($soldiers[$s]);
		}
        print("(Factory hasn't absorbed any fighter of type " . $s . ")" . PHP_EOL);
        return null;
	}
}

?>