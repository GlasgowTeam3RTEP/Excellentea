<! doctype html>

<html>

<head>
<style>

	body {
		 background-color: black;
	}
	

	
	input[type=button] {
    background-color: #ac0033;
    border: none;
    color: white;
    padding: 15px 25px;
    text-align: center;
    font-size: 16px;
    cursor: pointer;
	}

	input[type=button]:hover {
    background: grey;
	}
</style>


</head>
<body>

<script type = "text/javascript">

	function on_callPHP()
	{
		var result= "<?php php_func();?>";
		alert(result);
		return false;
	}
	
	function black_tea()
	{
		var result= "<?php blacktea();?>";
		alert(result);
		return false;
	}
	
	function green_tea()
	{
		var result= "<?php greentea();?>";
		alert(result);
		return false;
	}
	
</script>

<form action= "" method= "POST">
<input type= "button" value= "Activate" onclick = "on_callPHP()" style= "position: absolute; top: 450px; left: 350px"/>
<input type= "button" value= "Black Tea" onclick = "black_tea()" style= "position: absolute; top: 450px; left: 500px"/>
<input type= "button" value= "Green Tea" onclick = "green_tea()" style= "position: absolute; top: 450px; left: 650px"/>
</form>

<img src="Banner_Github.png" alt="Banner" align="middle">

	<?php
		function php_func()
		{
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
		}
		function blacktea()
		{
			$blacktea = fopen("black_tea.txt","w") or die("Unable to open file!");
			$txt="temperature: 85, time: 120";
			fwrite($blacktea,$txt);
			echo "It works!";
			fclose($blacktea); 
		}
		
		function greentea()
		{
			$greentea = fopen("green_tea.txt", "w") or die("Unable to open file!");
			$txt= "temperature:76.67, time: 120";
			fwrite($greentea,$txt);
			echo "It works too!";
			fclose($greentea);
			
		}
		
	?>
	
</body>


