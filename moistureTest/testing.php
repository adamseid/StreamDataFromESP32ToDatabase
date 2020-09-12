<html>
<body>

<?php

$dbname = 'testdatabase';
$dbuser = 'root';  
$dbpass = ''; 
$dbhost = 'localhost'; 

$connect = @mysqli_connect($dbhost,$dbuser,$dbpass,$dbname);

if(!$connect){
	echo "Error: " . mysqli_connect_error();
	exit();
}

echo "Connection Success!<br><br>";

$moisture_reading = $_GET["moisture_reading"];
$pump_condition = $_GET["pump_condition"];
$encoder_position = $_GET["encoder_position"];


$query = "INSERT INTO firsttesttable (Moisture , Pump , Encoder) VALUES ('$moisture_reading' , '$pump_condition' , '$encoder_position')";
$result = mysqli_query($connect,$query);

echo "Insertion Success!<br>";

?>
</body>
</html>
