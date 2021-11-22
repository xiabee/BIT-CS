var time1h,time1m,time1s//开始时间
var time2h,time2m,time2s//结束时间

window.onload=function()//window.onload在页面加载完成后触发
{ 
    time1h=new Date().getHours();//根据时间打招呼
    time1m=new Date().getMinutes();
    time1s=new Date().getSeconds();
}
function scorecount()//计算得分函数，同时显示总用时
{
    //var ddname=document.getElementsByName(username).value;
    var total=0;//记录总分
    var count=0;//每一题的分数
    var flag=0;//标记是否做对
    var sys=0;//标记是否选中
    var i;
    for(i=0;i<20;i++)//前面单选题
    {
        var ans=document.getElementsByName("q"+(i+1));//获取当前题目选项
        for(var j=0;j<ans.length;j++)
        {
            if(ans[j].checked)
            {
                if(ans[j].value=="*")
                total+=5;
            }
        }
    }

    time2h=new Date().getHours();//计算总用时
    time2m=new Date().getMinutes();
    time2s=new Date().getSeconds();
    var timeh=time2h-time1h;
    var timem=time2m-time1m;
    var times=time2s-time1s;
    if(times<0)
    {
        times+=60;
        timem-=1;
    }       
    if(timem<0)
    {
        timem+=60;
        timeh-=1;
    }
    var timetotal=timeh*3600+timem*60+times;//记录总时间
    gg=document.getElementById("ggmg");
    gg.value=parseInt(total);
    name=document.getElementById("ggname").value;
    timett=document.getElementById("ggtime");
    timett.value=timetotal;
    alert("亲爱的 "+name+" 同学：\n\n"+"你的最终得分为："+total+"分\n\n"+"用时："+timeh+"时"+timem+"分"+times+"秒");
    return true;
}