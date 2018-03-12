<?php

Class ship{
	public $x;
	public $y;
	public $hp;

	public function __construct(){
		$this->x = 0;
		$this->y = 0;
	}

	public function setxy( $arr )
	{
		$this->x = $arr['x'];
		$this->y = $arr['y'];
	}

	public function getxy(){
		$m = ['x' => $this->x, 'y' => $this->y];
		echo json_encode($m);
	}
}

?>