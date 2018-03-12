<?php
	session_start();
	$_SESSION['id'] = $_GET['id'];	
    include ('DB.class.php');
    $db = new DB(["10.21.0.96", "root", "bitnami", "battleship"]);
    $db->query("update users set HP = 5, x = '3', y = '3' where id = '1'");
    $db->query("update users set HP = 5, x = '146', y = '96' where id = '2'");
?>
<!doctype html>
<html>
    <head>
    	<script src="src.js" type="text/javascript">
    	</script>
    	<style type="text/css">
    		
    		#myCanvas{
    			position: absolute;
    		}

            .myhpbar{
                position: absolute;
                display: block;
                left: 7px;
                top: 5px;
                height: 15px;
                width: 300px;
            }
            .hishpbar{
                position: absolute;
                display: block;
                left: 1225px;
                top: 5px;
                height: 15px;
                width: 300px;
            }

            .hishpbar .body{
                position: relative;
                display: block;
                height: 15px;
                width: 100%;
                border: 3px solid black;
                overflow: hidden;
            }

            .myhpbar .body{
                position: relative;
                display: block;
                height: 15px;
                width: 100%;
                border: 3px solid black;
                overflow: hidden;
            }

            .hpbar{
                position: absolute;
                left: 0;
                top: 0;
                width: 100%;
                height: 100%;
                background-color: red;
                transition: all .5s ease;
            }
            .logo{
                position: absolute;
                left: 700px;
                top: -15px;
            }

            .buttons{
                position: absolute;
                top: 45px;
                left: 1550px;
                width: 45px;
                outline: 1px solid black;
                padding: 10px 10px 0 10px;
                text-align: center;
            }

            .buttons .btn{
                position: relative;
                display: inline-block;
                width: 40px;
                height: 40px;
                margin-bottom: 5px;
                border: 1px solid black;
            }

            .buttons .btn .nr{
                position: absolute;
                top: 0;
                left: 0;
                font-size: 10pt;
            }

            .selectedbtn{
                outline: 3px solid black;
            }

            .buttons .btn img{
                margin: 15px 0;
            }

    	</style>
    </head>
    <body onload="onload();">
    <br>
    <br>
    <canvas id="myCanvas" width="1520" height="1020" style="border:1px solid #000000;">
    	Your browser does not support the HTML5 canvas tag.
	</canvas>
    <h1 class="logo">Battleships&nbsp;&nbsp;&nbsp;<a href="logout.php">logout</a></h1>
    <div class="myhpbar">
        <div class="body">
            <span id="myhp" class="hpbar"></span>
        </div>
            <b>You </b><i> units:</i><b id="myhpunit">12</b>
    </div>
    <div class="hishpbar">
        <div class="body">
            <span id="hishp" class="hpbar"></span>
        </div>
            <b>Enemy </b><i> units:</i><b id="hishpunit">12</b>
    </div>
    <div class="buttons">
        <span class="btn selectedbtn"><span class="nr">1</span><img src="strightline.png"></span>
        <span class="btn"><span class="nr">2</span><img src="dashed.png"></span>
        <span class="btn"><span class="nr">3</span></span>
    </div>
    </body>
</html>