print = console.log

function Difference(from){
    var ct = new Date();
    return  (ct-from)/(1000*3600*24*365);
}

var birthDay = new Date(2002 , 1 , 28);

var year = document.getElementById("year");
var floating = document.getElementById("floating");

function update(refreshDuration){
    setInterval(function(){

        var dif = Difference(birthDay);
        var list = String(dif).split('.');

        floating.innerHTML = "."+list[1].slice(0,9);
        year.innerHTML = list[0];
        
    },refreshDuration);
}

update(100);
