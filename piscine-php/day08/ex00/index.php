<?php
session_start();
if (isset($_SESSION['logedin']) && $_SESSION['logedin'] === true){
  header('Location: main.php'); 
   echo "<meta http-equiv='refresh' content='0.1' >";
}
if (isset($_GET['err']))
{
    echo "<script>Alert('The game is full! try later!');</script>";
}
?>
<html>
  <head>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
    <style>
      #rcorners 
      {
        border-radius: 25px;
        border: 5px solid #297E92;
        padding: 20px; 
        width: 300px;
        height: 400px; 
        margin: 100 auto;
        background: #B2D0D7;
      }
      body{
        background-image: url('https://i.ytimg.com/vi/U-D5JVh6NLU/maxresdefault.jpg');
        background-repeat: no-repeat;
        background-size: 100%;
        position:relative;
      }
    </style>
  </head>
<body>
<div align='center' id='rcorners'>
    <h4>login</h4>
    <form method = 'POST'  name='login.php' action='login.php'>
    <h2>Username:</h2>
    <input type='text' name='login' value='' style='width: 250px; height: 35px;'>
      <br/>
    <h2>Password:</h2>
      <input type='password' name='passwd'  value='' style='width: 250px; height: 35px;'>
      <br/>
      <br/>
      <input type='submit' value='OK' name='submit' style='display: block; width: 35%;  '>
    </form> 
    <a href='create.html'><button style='width: 170px; height: 35px;'><b>Create your account</b></button></a>
    <br/>
     <br/>
</div>
<br/>
<br/>
<body>
</html>