var time1h,time1m,time1s//开始时间
var time2h,time2m,time2s//结束时间

window.onload=function()//window.onload在页面加载完成后触发
{ 
    time1h=new Date().getHours();//根据时间打招呼
	if(time1h<12)
		alert("Good Morning\n\nMy Friend!\n\nWelcome to the Principles of Management Test");
	else if(time1h<18)
		alert("Good Afternoon\n\nMy Friend!\n\nWelcome to the Principles of Management Test");
	else
        alert("Good Evening\n\nMy Friend!\n\nWelcome to the Principles of Management Test");
    time1m=new Date().getMinutes();
    time1s=new Date().getSeconds();
    setInterval(function()//显示当前时间的函数,每秒调用一次
    { 
        var date=new Date(); 
        var year=date.getFullYear(); //获取当前年份 
        var month=date.getMonth()+1; //获取当前月份 
        var da=date.getDate(); //获取当前日 
        var day=date.getDay(); //获取当前星期几 
        var hours=date.getHours(); //获取小时
        var minutes=date.getMinutes(); //获取分钟 
        var seconds=date.getSeconds(); //获取秒 
        var d=document.getElementById('timetime'); 
        var day1=["日","一","二","三","四","五","六"];
        d.innerHTML='当前时间: '+year+'年'+month+'月'+daye+'日'+' 星期'+day1[day]+' ' +hours+':'+minutes+':'+seconds; 
    },1000) 
}