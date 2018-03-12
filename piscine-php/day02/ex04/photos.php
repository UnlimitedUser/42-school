#!/usr/bin/php
<?php
function download_image1($image_url, $image_file){
    $fp = fopen ($image_file, 'w+');            

    $ch = curl_init($image_url);
   
    curl_setopt($ch, CURLOPT_FILE, $fp);         
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
    curl_setopt($ch, CURLOPT_TIMEOUT, 1000);     
    curl_setopt($ch, CURLOPT_USERAGENT, 'Mozilla/5.0');
  
    curl_exec($ch);

    curl_close($ch);                              
    fclose($fp);                                
}

	$html = file_get_contents($argv[1]);
	$result = array();
	preg_match_all('/<img.{0,}src=["|\/|h][[:graph:]]+/', $html, $match);
	$i = count($match[0]);
	$f = 0;
	while ($i != $f)
	{
		$val = substr(strstr($match[0][$f], "src="), 5);
	$vl = str_replace('"', '', $val);
	$vl = str_replace('>', '', $vl);
	if ($vl[0][0] == "/")
		$match[0][$f] = $argv[1] . $vl;
	else
		$match[0][$f] = $vl;
	$f++;
	}
	$val = $argv[1];
	if (substr($argv[1],0,7) == "http://")
		$val = substr($argv[1],7);
	if (file_exists($val) == FALSE)
		mkdir($val,0777,true);
	foreach ($match[0] as $key)
	{
		$imgurl = $key;
		$imagename = basename($imgurl);
		 download_image1($imgurl,$val."/".$imagename);
	}
?>