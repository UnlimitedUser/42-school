<?php

Class DB{
	public $db;

	public function __construct( $data )
	{
		$this->db = mysqli_connect($data[0] , $data[1], $data[2], $data[3]);
	}

	public function query( $q )
	{
		return mysqli_query($this->db, $q);
	}

	public function fetch( $r )
	{
		return mysqli_fetch_array($r, MYSQLI_ASSOC);
	}
}

?>