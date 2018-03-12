<?php

class Color
{
	public $red;
	public $green;
	public $blue;
	static $verbose = false;

	function __construct($color)
	{
		if (isset($color['red']) && isset($color['green']) && isset($color['blue']))
		{
			$this->red = intval($color['red']);
			$this->green = intval($color['green']);
			$this->blue = intval($color['blue']);
		}
		elseif (isset($color['rgb']))
		{
			$rgb = intval($color["rgb"]);
			$this->red = $rgb / 65281 % 256;
			$this->green = $rgb / 256 % 256;
			$this->blue = $rgb % 256;
		}
		if (self::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
	}

	function __destruct()
	{
		if (self::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
	}

	function __toString()
	{
		return (vsprintf("Color( red: %3d, green: %3d, blue: %3d )", array($this->red, $this->green, $this->blue)));
	}

	function add($a)
    {
        return (new Color(array('red' => $this->red + $a->red, 'green' => $this->green + $a->green, 'blue' => $this->blue + $a->blue)));
    }

    function sub($b)
    {
        return (new Color(array('red' => $this->red - $b->red, 'green' => $this->green - $b->green, 'blue' => $this->blue - $b->blue)));
    }

    function mult($m)
    {
        return (new Color(array('red' => $this->red * $m, 'green' => $this->green * $m, 'blue' => $this->blue * $m)));
    }

    static function doc()
    {
    	if (file_exists("Color.doc.txt"))
    		echo "\n".file_get_contents("Color.doc.txt")."\n";
    }
}

?>