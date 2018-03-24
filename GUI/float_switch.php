<?php
		//this piece of code establishes the communication of the web interface with the main program 
		//for the activation of the tea maker
		//through the text file float_switch 
		$stringvar_conditiontrue= "Please select type of tea";
		$stringvar_conditionfalse= "Please fill up water";
		$stringvar_true= "True";
		$check= fopen("float_switch.txt","r") or die("Unable to open file!");
		$create_string= file_get_contents("float_switch.txt");
		$compare=strcmp($create_string,$stringvar_true);
		 
		if ($compare == 0){

			echo $stringvar_conditiontrue;
		}else {
			echo $stringvar_conditionfalse;
		}
		fclose($check);
?>

