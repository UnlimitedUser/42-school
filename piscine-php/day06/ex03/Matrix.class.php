<?php

class Matrix
{
    const IDENTITY = "IDENTITY";
    const SCALE = "SCALE";
    const RX = "Ox ROTATION";
    const RY = "Oy ROTATION";
    const RZ = "Oz ROTATION";
    const TRANSLATION = "TRANSLATION";
    const PROJECTION = "PROJECTION";

    private $_matrix = array(array(1, 0, 0, 0), array(0, 1, 0, 0), array(0, 0, 1, 0), array(0, 0, 0, 1));
    private $_preset;
    private $_scale;
    private $_angle;
    private $_vtc;
    private $_fov;
    private $_ratio;
    private $_near;
    private $_far;

    static $verbose = false;

	function __construct($arr)
    {   
        if (isset($arr['preset']))
            $this->_preset = $arr['preset'];
        if (isset($arr['scale']))
            $this->_scale = $arr['scale'];
        if (isset($arr['angle']))
            $this->_angle = $arr['angle'];
        if (isset($arr['vtc']))
            $this->_vtc = $arr['vtc'];
        if (isset($arr['fov']))
            $this->_fov = $arr['fov'];
        if (isset($arr['ratio']))
            $this->_ratio = $arr['ratio'];
        if (isset($arr['near']))
            $this->_near = $arr['near'];
        if (isset($arr['far']))
            $this->_far = $arr['far'];
        $_matrix = array_fill(0, 4, array_fill(0, 4, 0));
        $this->createMatrix();
        if (self::$verbose)
        {
            if ($this->_preset == self::IDENTITY)
                echo "Matrix " . $this->_preset . " instance constructed\n";
            else
                echo "Matrix " . $this->_preset . " preset instance constructed\n";
        }
	}

    function __destruct()
    {
        if (Self::$verbose)
            printf("Matrix instance destructed\n");
    }

    private function createMatrix()
    {
        switch ($this->_preset)
        {
            case (self::IDENTITY):
                $this->identity(1);
                break;
            case (self::TRANSLATION):
                $this->translation();
                break;
            case (self::SCALE):
                $this->identity($this->_scale);
                break;
            case (self::RX):
                $this->rotation_x();
                break;
            case (self::RY):
                $this->rotation_y();
                break;
            case (self::RZ):
                $this->rotation_z();
                break;
            case (self::PROJECTION):
                $this->projection();
                break;
        }
    }

    private function identity($scale)
    {
        $this->_matrix[0][0] = $scale;
        $this->_matrix[1][1] = $scale;
        $this->_matrix[2][2] = $scale;
        $this->_matrix[3][3] = 1;
    }

    private function translation()
    {
        $this->identity(1);
        $this->_matrix[0][3] = $this->_vtc->getX();
        $this->_matrix[1][3] = $this->_vtc->getY();
        $this->_matrix[2][3] = $this->_vtc->getZ();
    }

    private function rotation_x()
    {
        $this->identity(1);
        $this->_matrix[0][0] = 1;
        $this->_matrix[1][1] = cos($this->_angle);
        $this->_matrix[1][2] = -sin($this->_angle);
        $this->_matrix[2][1] = sin($this->_angle);
        $this->_matrix[2][2] = cos($this->_angle);
    }

    private function rotation_y()
    {
        $this->identity(1);
        $this->_matrix[0][0] = cos($this->_angle);
        $this->_matrix[0][2] = sin($this->_angle);
        $this->_matrix[1][1] = 1;
        $this->_matrix[2][0] = -sin($this->_angle);
        $this->_matrix[2][2] = cos($this->_angle);
    }

    private function rotation_z()
    {
        $this->identity(1);
        $this->_matrix[0][0] = cos($this->_angle);
        $this->_matrix[0][1] = -sin($this->_angle);
        $this->_matrix[1][0] = sin($this->_angle);
        $this->_matrix[1][1] = cos($this->_angle);
        $this->_matrix[2][2] = 1;
    }

    private function projection()
    {
        $this->identity(1);
        $this->_matrix[1][1] = 1 / tan(0.5 * deg2rad($this->_fov));
        $this->_matrix[0][0] = $this->_matrix[1][1] / $this->_ratio;
        $this->_matrix[2][2] = -1 * (-$this->_near - $this->_far) / ($this->_near - $this->_far);
        $this->_matrix[3][2] = -1;
        $this->_matrix[2][3] = (2 * $this->_near * $this->_far) / ($this->_near - $this->_far);
        $this->_matrix[3][3] = 0;
    }

    public function mult(Matrix $rhs)
    {
        $old_verbose = Matrix::$verbose;
        Matrix::$verbose = false;
        $result = new Matrix(array('preset' => Matrix::IDENTITY));
        Matrix::$verbose = $old_verbose;
        for ($i = 0; $i < 4; $i++) {
            for ($j = 0; $j < 4; $j++)
                $result->_matrix[$i][$j] = $this->_matrix[$i][0] * $rhs->_matrix[0][$j] + $this->_matrix[$i][1] * $rhs->_matrix[1][$j] + $this->_matrix[$i][2] * $rhs->_matrix[2][$j] + $this->_matrix[$i][3] * $rhs->_matrix[3][$j];
        }
        return ($result);
    }

    public function transformVertex(Vertex $vtx)
    {
        $tmp = array();
        $tmp['x'] = ($vtx->getX() * $this->_matrix[0][0]) + ($vtx->getY() * $this->_matrix[0][1]) + ($vtx->getZ() * $this->_matrix[0][2]) + ($vtx->getW() * $this->_matrix[0][3]);
        $tmp['y'] = ($vtx->getX() * $this->_matrix[1][0]) + ($vtx->getY() * $this->_matrix[1][1]) + ($vtx->getZ() * $this->_matrix[1][2]) + ($vtx->getW() * $this->_matrix[1][3]);
        $tmp['z'] = ($vtx->getX() * $this->_matrix[2][0]) + ($vtx->getY() * $this->_matrix[2][1]) + ($vtx->getZ() * $this->_matrix[2][2]) + ($vtx->getW() * $this->_matrix[2][3]);
        $tmp['w'] = ($vtx->getX() * $this->_matrix[3][0]) + ($vtx->getY() * $this->_matrix[3][1]) + ($vtx->getZ() * $this->_matrix[3][2]) + ($vtx->getW() * $this->_matrix[3][3]);
        $tmp['color'] = $vtx->getColor();
        return new Vertex($tmp);
    }

    static function doc()
    {
        if (file_exists("Matrix.doc.txt"))
            echo "\n".file_get_contents("Matrix.doc.txt")."\n";
    }

    function __toString()
    {
        $f = "M | vtcX | vtcY | vtcZ | vtxO\n-----------------------------\nx | %0.2f | %0.2f | %0.2f | %0.2f\ny | %0.2f | %0.2f | %0.2f | %0.2f\nz | %0.2f | %0.2f | %0.2f | %0.2f\nw | %0.2f | %0.2f | %0.2f | %0.2f";
        return vsprintf($f, array($this->_matrix[0][0], $this->_matrix[0][1], $this->_matrix[0][2], $this->_matrix[0][3], $this->_matrix[1][0], $this->_matrix[1][1], $this->_matrix[1][2], $this->_matrix[1][3],
                        $this->_matrix[2][0], $this->_matrix[2][1], $this->_matrix[2][2], $this->_matrix[2][3], $this->_matrix[3][0], $this->_matrix[3][1], $this->_matrix[3][2], $this->_matrix[3][3]));
    }
}

?>