<!DOCTYPE html>

<?php
    $page = $_SERVER['PHP_SELF'];
    $sec = "10";
?>

<html>
    <head>
	<meta http-equiv="refresh" content="<?php echo $sec?>;URL='<?php echo $page?>'">
    <style>
    
        body {
            text-align: center;
        }
    
    </style>
    </head>

    <body>

	<?php
	
	ini_set('display_errors',1);
        error_reporting(E_ALL);
	$started = FALSE;
	$done = FALSE;
        $filename = "/var/www/html/config";
        $handle = fopen($filename, "r") or die("Unable to open file");
        while (!feof($handle)) {
            $field = explode("\t", fgets($handle));
            $tag = $field[0];
            if ( ! isset($field[1])) {
                   $field[1] = null;
                }
            $value = $field[1];
	    
	    if ($tag == "PROGR") {
		if ($value == "YES") {
		    $started = TRUE;
		}

	    } else {
		if ($tag == "DONE") {
		    if ($value == "YES") {
			$done == TRUE;
		    }
		}
	    }
        }
        fclose($handle);
	
	if ($done) {
	    echo "Your tea is ready!!!";
	} else {
	    if ($started) {
		echo "Your tea is being made :)";
	    } else {
		echo "Excellentea is preparing to make your tea.";
	    }
	}
    ?>

    </body>
</html>