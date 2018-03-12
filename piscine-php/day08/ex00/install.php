<?php
    include('DB.class.php');
    $db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
    $conn = $db->db;

    if ($db->query("CREATE TABLE `users` (
                  `id` int(11) NOT NULL AUTO_INCREMENT,
                  `name` varchar(60) NOT NULL,
                  `ship` varchar(255) NOT NULL,
                  `x` int(11) NOT NULL,
                  `y` int(11) NOT NULL,
                  `HP` int(11) NOT NULL,
                  `arrmor` int(11) NOT NULL,
                  PRIMARY KEY (`id`)
                )"))
    {
        $db->query("INSERT INTO `battleship`.`users` (`id`, `name`, `ship`, `x`, `y`, `HP`, `arrmor`) VALUES (null, 'user1', '1', '5', '5', '5', '9')");
        $db->query("INSERT INTO `battleship`.`users` (`id`, `name`, `ship`, `x`, `y`, `HP`, `arrmor`) VALUES (null, 'user2', '1', '146', '96', '5', '9')");
        echo "Table created successfully<br/>";
    }

    if (mysqli_query($conn, "CREATE TABLE player(id int NOT NULL AUTO_INCREMENT, login varchar(60), passwd varchar(255), ships varchar(255), PRIMARY KEY(ID));"))
    {
        echo "Table created successfully<br/>";
    }
    else
    {
        echo "Error creating table: ". mysqli_error($conn)."<br/>";
    }
    
    
    // if (mysqli_query($conn, "CREATE TABLE ships(id int NOT NULL AUTO_INCREMENT, name varchar(60), price int NOT NULL, life int, img_url TEXT, PRIMARY KEY(ID));"))
    // {
    //     echo "Table created successfully<br/>";
    // }
    // else
    // {
    //     echo "Error creating table: ". mysqli_error($conn)."<br/>";
    // }
    mysqli_close($conn);
    echo " <a href='index.php'><button>Go play</button></a>";
?>