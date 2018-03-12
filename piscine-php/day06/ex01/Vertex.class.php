<?php 

require_once 'Color.class.php';

class Vertex
{
    private $_x;
    private $_y;
    private $_z;
    private $_w = 1;
    private $_color;
    static $verbose = false;

    function __construct($ver)
    {
    	$this->_x = $ver['x'];
    	$this->_y = $ver['y'];
    	$this->_z = $ver['z'];
    	if (isset($ver['w']))
    		$this->_w = $ver['w'];
    	if (isset($ver["color"]) && $ver["color"] instanceof Color)
    		$this->_color = $ver["color"];
    	else
    		$this->_color = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
    	if (self::$verbose)
            printf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, Color( red: %3d, green: %3d, blue: %3d ) ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue);
    }

    function __destruct()
    {
    	if (self::$verbose)
    		printf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, Color( red: %3d, green: %3d, blue: %3d ) ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue);
    }

    static function doc()
    {
    	if (file_exists("Vertex.doc.txt"))
    		echo "\n".file_get_contents("Vertex.doc.txt")."\n";
    }

    function __toString()
    {
    	if (self::$verbose)
        	return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, Color( red: %3d, green: %3d, blue: %3d ) )", array($this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue)));
        return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f )", array($this->_x, $this->_y, $this->_z, $this->_w)));
    }

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
	public function getColor() { return $this->_color; }
	public function setX($nb) { $this->_x = $nb; }
	public function setY($nb) { $this->_y = $nb; }
	public function setZ($nb) { $this->_z = $nb; }
	public function setW($nb) { $this->_w = $nb; }
	public function setColor(Color $Color) { $this->_color = $Color; }


}

?>