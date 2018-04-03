<!DOCTYPE html>
<html>
    <head>
    <style>
    
        body {
            text-align: center;
        }
    
    </style>
    </head>

    <body>

    Thanks for your choice! <br>
    
    <?php
	$temp = $_GET["temp"];
	$time = $_GET["time"];
        ini_set('display_errors',1);
        error_reporting(E_ALL); 
        $read = fopen("/var/www/html/config", "r") or die("Unable to open reading file");
	$write = fopen("/var/www/html/config.tmp", "w") or die("Unable to open writing file");
	$replaced = FALSE;

        while (!feof($read)) {
            $line = fgets($read);

	    if (stristr($line,"MAKE")) {
		$line = "MAKE\tYES\n";
		$replaced = TRUE;
	    }

	    if (stristr($line,"TEMP")) {
		$line = "TEMP\t$temp\n";
		$replaced = TRUE;
	    }

	    if (stristr($line,"TIME")) {
		$line = "TIME\t$time\n";
		$replaced = TRUE;
	    }
	    fputs($write, $line);
        }
        fclose($read);
	fclose($write);

	if ($replaced) {
	    rename('config.tmp', 'config');
	} else {
	    unlink('config.tmp');
	}

	header( "refresh:3;url=/status.php" );
    ?>


    </body>
</html>