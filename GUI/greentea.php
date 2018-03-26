<?php
    header('Access-Control-Allow-Origin: *');
    $greentea = fopen("tea_type.txt", "w") or die("Unable to open file!");
    $txt= "temperature:76.67, time: 120";
    fwrite($greentea,$txt);
    echo "It works too!";
    fclose($greentea);
    
    ?>
