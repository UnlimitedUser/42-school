<?php

class NightsWatch implements IFighter
{

    private $camp = array();

    public function recruit($s)
    {
        $this->camp[] = $s;
    }

    function fight()
    {
        foreach ($this->camp as $s) {
            if (method_exists(get_class($s), 'fight'))
                $s->fight();
        }
    }
}

?>