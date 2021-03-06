<?php

class Vector
{
    private $_x;
    private $_y;
    private $_z;
    private $_w = 0;
    static $verbose = false;

    function __construct($vect)
    {
    	if (isset($vect['dest']) && $vect['dest'] instanceof Vertex)
    	{
	    	$orig = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0));
	    	if (isset($vect['orig']) && $vect['orig'] instanceof Vertex)
	            $orig = new Vertex(array('x' => $vect['orig']->getX(), 'y' => $vect['orig']->getY(), 'z' => $vect['orig']->getZ()));
	        $this->_x = $vect['dest']->getX() - $orig->getX();
	        $this->_y = $vect['dest']->getY() - $orig->getY();
	        $this->_z = $vect['dest']->getZ() - $orig->getZ();
	        $this->_w = 0;
	    }
	    if (self::$verbose)
        	printf("Vector( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
    }

    function __destruct()
    {
    	if (self::$verbose)
    		printf("Vector( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
    }

    function magnitude()
    {
    	return (float)sqrt(($this->_x * $this->_x) + ($this->_y * $this->_y) + ($this->_z * $this->_z));
    }

    function normalize()
    {
    	$magn = $this->magnitude();
        if ($magn == 1)
            return clone $this;
        return new Vector(array('dest' => new Vertex(array('x' => $this->_x / $magn, 'y' => $this->_y / $magn, 'z' => $this->_z / $magn))));
    }

    function add(Vector $rhs)
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->_x + $rhs->_x, 'y' => $this->_y + $rhs->_y, 'z' => $this->_z + $rhs->_z))));
    }

    function sub(Vector $rhs)
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->_x - $rhs->_x, 'y' => $this->_y - $rhs->_y, 'z' => $this->_z - $rhs->_z))));
    }

    function opposite()
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->_x * -1, 'y' => $this->_y * -1, 'z' => $this->_z * -1))));
    }

    function scalarProduct($k)
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->_x * $k, 'y' => $this->_y * $k, 'z' => $this->_z * $k))));
    }

    function dotProduct(Vector $rhs)
    {
        return (float)(($this->_x * $rhs->_x) + ($this->_y * $rhs->_y) + ($this->_z * $rhs->_z));
    }

    function __toString()
    {
        return (vsprintf("Vector( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f )", array($this->_x, $this->_y, $this->_z, $this->_w)));
    }

    function cos(Vector $rhs)
    {
        return ((($this->_x * $rhs->_x) + ($this->_y * $rhs->_y) + ($this->_z * $rhs->_z)) / sqrt((($this->_x * $this->_x) + ($this->_y * $this->_y) + ($this->_z * $this->_z)) * (($rhs->_x * $rhs->_x) + ($rhs->_y * $rhs->_y) + ($rhs->_z * $rhs->_z))));
    }

    static function doc()
    {
    	if (file_exists("Vector.doc.txt"))
    		echo "\n".file_get_contents("Vector.doc.txt")."\n";
    }


    function crossProduct(Vector $rhs)
    {
    	return new Vector(array('dest' => new Vertex(array(
            'x' => $this->_y * $rhs->getZ() - $this->_z * $rhs->getY(),
            'y' => $this->_z * $rhs->getX() - $this->_x * $rhs->getZ(),
            'z' => $this->_x * $rhs->getY() - $this->_y * $rhs->getX()
        ))));
    }

    function getX()
    {
        return $this->_x;
    }

    function getY()
    {
        return $this->_y;
    }

    function getZ()
    {
        return $this->_z;
    }

    function getW()
    {
        return $this->_w;
    }
}

?>