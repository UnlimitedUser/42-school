
var c;
var ctx;
var matr;
var x1 = 5,y1 = 5;
var x2 = 146,y2 = 96;
var mode = 1;


function draw_grid(){
  var i, j, ix, jx;
  ctx.clearRect(0, 0, c.width, c.height);
  ix = 0;
  for (i = 0; i < 1500; i += 10)
  {
    jx = 0;
    for( j = 0; j < 1000; j += 10)
    {
      ctx.beginPath();
      ctx.lineWidth="0";
      ctx.strokeStyle="rgba(0,0,0,.05)";
      ctx.rect(i + 10, j + 10, 10, 10);
      if (matr[ix][jx] == 1)
      {
        ctx.fillStyle = "blue";
        ctx.fill();
      }
      else if (matr[ix][jx] == 2)
      {
        ctx.fillStyle = "red";
        ctx.fill();
      }
      else if (matr[ix][jx] == 5)
      {
        ctx.fillStyle = "black";
        ctx.fill();
      }
      else
        ctx.stroke();
      jx++;
    }
    ix++;
  } 
}

setInterval(getdata, 100);
setInterval(hprefresh, 100);

var gameover = false;
function hprefresh(){
  if (gameover)
    return ;
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (xhttp.readyState == 4 && xhttp.status == 200) {
      myObj = JSON.parse(xhttp.responseText);
      document.getElementById('myhpunit').innerHTML = parseInt(myObj['myhp']);
      document.getElementById('hishpunit').innerHTML = parseInt(myObj['hishp']);
      document.getElementById('myhp').style.width = (parseInt(myObj['myhp']) / 5 * 100) + '%';
      document.getElementById('hishp').style.width = (parseInt(myObj['hishp']) / 5 * 100) + '%';
      if (parseInt(myObj['myhp']) <= 0)
      {
        gameover = true;
        alert ("You loose!");
      }
      if (parseInt(myObj['hishp']) <= 0)
      {
        gameover = true;
        alert ("<<<< You WON >>>>")
      }
    }
  }
  xhttp.open("GET", "refreshhp.php", true);
  xhttp.send();
}

function onload(){
  c = document.getElementById("myCanvas");
  ctx = c.getContext("2d");
  matr = new Array(150);
  for (i = 0; i <= 150; i++)
    matr[i] = new Array(100);
  for (i = 0; i < 150; i++)
  {
    for( j = 0; j < 100; j++)
    {
      matr[i][j] = 0;
    }
  }
  for (i = 0; i < 150; i++)
  {
    matr[i][0] = 5;
    matr[i][99] = 5;
  }
  for (i = 0; i < 100; i++)
  {
    matr[0][i] = 5;
    matr[149][i] = 5;
  }
  draw_grid();
  getdata();
}
function getdata() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (xhttp.readyState == 4 && xhttp.status == 200) {
     	myObj = JSON.parse(xhttp.responseText);
      matr[x1][y1] = 0;
      matr[x1 + 1][y1 - 1] = 0;
      matr[x1 + 1][y1 + 1] = 0;
      matr[x1 - 1][y1 - 1] = 0;
      matr[x1 - 1][y1 + 1] = 0;
      matr[x2 + 1][y2 - 1] = 0;
      matr[x2 + 1][y2 + 1] = 0;
      matr[x2 - 1][y2 - 1] = 0;
      matr[x2 - 1][y2 + 1] = 0;
      matr[x2][y2] = 0;
     	x1 = parseInt(myObj['x1']);
     	y1 = parseInt(myObj['y1']);
     	x2 = parseInt(myObj['x2']);
     	y2 = parseInt(myObj['y2']);
     	matr[x1][y1] = 1;
      matr[x1 + 1][y1 - 1] = 1;
      matr[x1 + 1][y1 + 1] = 1;
      matr[x1 - 1][y1 - 1] = 1;
      matr[x1 - 1][y1 + 1] = 1;
      matr[x2 + 1][y2 - 1] = 2;
      matr[x2 + 1][y2 + 1] = 2;
      matr[x2 - 1][y2 - 1] = 2;
      matr[x2 - 1][y2 + 1] = 2;
     	matr[x2][y2] = 2;
     	draw_grid();
    }
  }
  xhttp.open("GET", "getdata.php", true);
  xhttp.send();
}

var sent = true;
function sentdata(x,y) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (xhttp.readyState == 4 && xhttp.status == 200) {
      sent = true;
    }
  }
  xhttp.open("GET", "setdata.php?x="+x+"&y="+y, true);
  xhttp.send();
}

function shootEnemy(){
  var xhttp = new XMLHttpRequest();
   xhttp.onreadystatechange = function() {
    if (xhttp.readyState == 4 && xhttp.status == 200) {
      hprefresh();
    }
  }
  xhttp.open("GET", "shoot.php", true);
  xhttp.send();
}

function shootLeft(){
  if (mode < 3)
  {
    for(i = x1-1; i > 0; i-=mode)
    {
      if (matr[i][y1] == 2)
        shootEnemy();
      if (matr[i][y1] != 0)
        break ;
        matr[i][y1] = 5;
    }
  }
  else
  {
    for(i = x1-1; i > 0; i-=1)
    {
      matr[i][y1] = 0;
    }
  }
}

function shootRight(){
  if (mode < 3)
  {
    for(i = x1+1; i < 149; i += mode)
    {
      if (matr[i][y1] == 2)
        shootEnemy();
      if (matr[i][y1] != 0)
        break ;
        matr[i][y1] = 5;
    }
  }
  else
  {
    for(i = x1+1; i < 149; i += 1)
    {
        matr[i][y1] = 0;
    }
  }
}

function shootDown(){
  if (mode < 3)
  {
    for(i = y1 + 1; i < 99; i += mode)
    {
      if (matr[x1][i] == 2)
        shootEnemy();
      if (matr[x1][i] != 0)
        break ;
        matr[x1][i] = 5;
    } 
  }
  else
  {
    for(i = y1 + 1; i < 99; i += 1)
    {
        matr[x1][i] = 0;
    } 
  }
}

function shootUp(){
  if (mode < 3)
  {
    for(i = y1 - 1; i > 0; i -= mode)
    {
      if (matr[x1][i] == 2)
        shootEnemy();
      if (matr[x1][i] != 0)
        break ;
      matr[x1][i] = 5;
    }
  }
  else
  {
    for(i = y1 - 1; i > 0; i -= 1)
    {
      matr[x1][i] = 0;
    }
  }
}

function selectbtn(nr){
  var btn = document.getElementsByClassName("btn");
  for(i=0; i < btn.length; i++)
    btn[i].setAttribute('class', 'btn');
  btn[nr - 1].setAttribute('class', 'btn selectedbtn');
  mode = nr;
}

document.onkeydown = checkKey;

function checkKey(e) {

    e = e || window.event;

    if (!sent)
      return;
    if (e.keyCode == '38') {
      	//up
        if (y1 > 0 && matr[x1][y1 - 2] == 0 && matr[x1 - 1][y1 - 2] == 0 && matr[x1 + 1][y1 - 2] == 0)
        {
          sent = false;
        	sentdata(x1, y1 - 1);
        }
    }
    else if (e.keyCode == '40') {
        // down arrow
        if (y1 < 99 && matr[x1][y1 + 2] == 0 && matr[x1 - 1][y1 + 2] == 0 && matr[x1 + 1][y1 + 2] == 0)
        {
          sent = false;
          sentdata(x1, y1 + 1);
        }
    }
    else if (e.keyCode == '37') {
         // left arrow
         if (x1 > 0 && matr[x1 - 2][y1] == 0  && matr[x1 - 2][y1 - 1] == 0 && matr[x1 - 2][y1 + 1] == 0)
         {
            sent = false;
            sentdata(x1 - 1, y1);
         }
    }
    else if (e.keyCode == '39') {
        // right arrow
        if (x1 < 149 && matr[x1 + 2][y1] == 0 && matr[x1 + 2][y1 - 1] == 0 && matr[x1 + 2][y1 + 1] == 0)
        {
          sent = false;
          sentdata(x1 + 1, y1);
        }
    }
    if (e.keyCode == '65')
    {
      //a
      shootLeft();
    }else
    if (e.keyCode == '68')
    {
      //d
      shootRight();
    }else
    if (e.keyCode == '83')
    {
      //s
      shootDown();
    }else
    if (e.keyCode == '87')
    {
      //w
      shootUp();
    }else
     if (e.keyCode == '49')
    {
      //1
      selectbtn(1);
    }else
    if (e.keyCode == '50')
    {
      //2
      selectbtn(2);
    }else
    if (e.keyCode == '51')
    {
      //3
      selectbtn(3);
    }
}
