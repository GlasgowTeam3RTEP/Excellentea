<?php
        header('Access-Control-Allow-Origin: *');
		if($_POST['action']=='call_this'){
		$blacktea = fopen("tea_type.txt","w") or die("Unable to open file!");
		$txt="temperature: 85, time: 120";
        echo "It works!";
        //print($txt);
		fwrite($blacktea,$txt);
		fclose($blacktea); 
		}
	
?>
