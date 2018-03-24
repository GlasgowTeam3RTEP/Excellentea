<?php
	
	$stringvar_inprogress= "Tea in progress";
	$stringvar_ready= "Tea is ready";
	$stringvar_true= "True";
	$check_progress= fopen("progress.txt","r") or die("Unable to open file!");
	$create_string= file_get_contents("progress.txt");
	$compare=strcmp($create_string,$stringvar_true);
		 
	if ($compare == 0){
		echo $stringvar_ready;
		}else {
	echo $stringvar_inprogress;
		}
	fclose($check);
?>