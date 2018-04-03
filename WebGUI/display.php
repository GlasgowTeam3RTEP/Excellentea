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


    <?php
        ini_set('display_errors',1);
        error_reporting(E_ALL);
        $filename = "/var/www/html/config";
        $handle = fopen($filename, "r+") or die("Unable to open file");
        while (!feof($handle)) {
            $field = explode("\t", fgets($handle));
            $tag = $field[0];
            if ( ! isset($field[1])) {
                   $field[1] = null;
                }
            $value = $field[1];
	    echo "$tag <b>--></b> $value <br>";
        }
        fclose($handle);
    ?>


    </body>
</html>