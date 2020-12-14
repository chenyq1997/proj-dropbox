var l=0;
var min = 10000000000;
var max = 0;
var filenum = 0;

function upload(s) {
	var f=document.getElementById('file'+s).files[0];
	var r= new FileReader();
	r.onload=function() {
		info = this.result;
		console.log(s);
		document.getElementById("size"+s).innerHTML = info.length;
		l += info.length;
		if (max < info.length) max = info.length;
		if (min > info.length) min = info.length;
		filenum+=1;
	};
	r.readAsText(f,"UTF-8");
}

var isHide=true;
function hide(){
	var tab=document.getElementById('tab') 
	var rows=tab.rows;
	var len=tab.rows.length;
	// tab.style.display='';
	for(var i=0;i < len;i++){
		console.log(tab);
		if (isHide) {
			rows[i].style.display='';
		}else{
			rows[i].style.display='none';
		}
	}
	isHide=!isHide
}

function dropbox(){
	document.getElementById("filesize").innerHTML = filenum;
	document.getElementById("orsize").innerHTML = l;
	document.getElementById("comsize").innerHTML = max + parseInt(min/50) * filenum;
}