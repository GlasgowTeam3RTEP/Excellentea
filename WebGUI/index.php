<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>

      div {
        text-align: center;
      }

      h1 {
      
      }

      p {
        font-weigth: bold;
        text-transform: uppercase;
      }

      p.red {
        color: #ff0000;
      }

      p.green {
        color: #00ff00;
      }

      .button {
        padding: 15px 25px;
        font-size: 24px;
        text-align: center;
        cursor: pointer;
        outline: none;
        color: #fff;
        background-color: #4CAF50;
        border: none;
        border-radius: 15px;
        box-shadow: 0 9px #999;
      }

      .button:hover:enabled {background-color: #3e8e41}

      .button:active:enabled {
        background-color: #3e8e41;
        box-shadow: 0 5px #666;
        transform: translateY(4px);
      }
    </style>
  </head>
  

<body>

    <div>
      <h1>Excellentea</h1>

      <?php
        ini_set('display_errors',1);
        error_reporting(E_ALL);
	$filename = "/var/www/html/config";
	$ready = FALSE;
	if (file_exists($filename)){
	    $handle = fopen($filename, "r") or die("Unable to open file!");
            while (!feof($handle)) {
                $field = explode("\t", trim(fgets($handle), "\n"));
                $tag = $field[0];
                if ( ! isset($field[1])) {
                   $field[1] = null;
                }
                $value = $field[1];
		if ($tag == "READY") {
                    if ($value == "YES") {
                        $ready = TRUE;
                    }
		    break;
                }            
            }
            fclose($handle);
	} 

	if ($ready){
	    echo '<p class="green">Ready</p>';
	} else {
	    echo '<p class="red">Not ready</p>';
	}
	?>

    </div>

    <div>
	<form action="blackTea.php" method="get">
	    <button type="input" class="button" <?php if (!$ready){ ?> disabled <?php } ?>>Black Tea</button>
	</form>
	<br>

    </div>

    <div>
	<form action="greenTea.php" method="get">
	    <button type="input" class="button" <?php if (!$ready){ ?> disabled <?php } ?>>Green Tea</button>
	</form>
	<br>
    </div>
    
    <div>
	<form action="definePar.php" method="get">
	    <button type="input" class="button" <?php if (!$ready){ ?> disabled <?php } ?>>Custom Tea</button>
	</form>
	<br>
    </div>

  </body>
</html>
