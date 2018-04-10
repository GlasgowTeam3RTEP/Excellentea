<html>
    <head>
    <style>
    
        body {
            text-align: center;
        }
    
    </style>
    </head>


    <body>

	<form action="customTea.php" method="get">
	    Water temperature [°C]: <input type="number" name="temp" min="20" max="100" required><br>
	    Brewing time [min]: <input type="number" name="time" min="1" max="60" required><br>
	    <input type="submit" name="submit" value="Submit">
	    <input type="reset" name="reset" value="Reset">
	</form>

    </body>
</html> 