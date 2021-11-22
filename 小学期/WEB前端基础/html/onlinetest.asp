<!--希望老师能用chrome浏览器打开-->
<!--希望老师能用chrome浏览器打开-->
<!--希望老师能用chrome浏览器打开-->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Online Test</title>
    <!--导库-->
    <link type="text/css" rel="stylesheet" href="../XiaBee_files/default.css">
    <script src="../XiaBee_files/score.js" type="text/javascript"></script>
    <script src="../XiaBee_files/time.js" type="text/javascript"></script>
</head>
<body class="background">
           <div>
            <div id="timetime"></div><!--显示当前日期、时间 -->
           </div>
    <div class="center">
        <hr class="hr">
        <h1 class="H1" > WELCOME TO THE ONLINE TEST!</h1>
            <h1>------Just Do It</h1>
        <hr class="hr">
        <!-- 空iframe，用于协助处理form提交后不进行页面跳转的问题 -->
        <iframe id="iframe_display" name="iframe_display" style="display: none;"></iframe>
        <form name="questions" action="../XiaBee_files/scores.asp" method="POST" onsubmit="return scorecount()" role="form" target="iframe_display">
            <fieldset>
                您的姓名：<input type="text" name="username" id="ggname">
            </fieldset>
            <p class="divcenter"> <strong>
                   &emsp14;&emsp14;&emsp14;&emsp14; 管理学是一门综合性的交叉学科，是系统研究管理活动的基本规律和一般方法的科学。管理学是适应现代社会化大生产的需要产生的，它的目的是：研究在现有的条件下，如何通过合理的组织和配置人、财、物等因素，提高生产力的水平。<br>
                   &emsp14;&emsp14;&emsp14;&emsp14;管理是指在特定的环境下，管理者通过执行计划、组织、领导、控制等职能，整合组织的各项资源，实现组织既定目标的活动过程。<br>
                   &emsp14;&emsp14;&emsp14;&emsp14;现在，精通管原的你，来复（yu）习（xi）一下管理学原理的知识叭！<br><br>
                一、单选题<br>
                1.事业部结构的组织形式的基本原则是<br>
                <input type="radio" name="q1" value="*">A.集中决策，分散经营<br>
                <input type="radio" name="q1" value="0">B.集中决策，集中经营<br>
                <input type="radio" name="q1" value="0">C.分散决策，集中经营<br>
                <input type="radio" name="q1" value="0">D.分散决策，分散经营<br>
                <br>
                2.管理者在作为组织的代表发履行礼仪性和象征性义务时，其扮演的角色是<br>
                <input type="radio" name="q2" value="0">A.决策制定方面<br>
                <input type="radio" name="q2" value="0">B.信息传递方面<br>
                <input type="radio" name="q2" value="*">C.人际关系方面<br>
                <input type="radio" name="q2" value="0">D.组织管理方面<br>
                <br>
                3.法约尔认为任何企业都有六种基本活动或职能，即:<br>
                <input type="radio" name="q3" value="0">A.生产、经营、安全、销售、核算、管理<br>
                <input type="radio" name="q3" value="0">B.技术、商业、财务、安全、核算、管理<br>
                <input type="radio" name="q3" value="0">C.技术、经济、安全、财务、核算、管理<br>
                <input type="radio" name="q3" value="*">D.生产、商业、财务、安全、会计、管理<br>
                <br>
                4.古典经济学家亚当.斯密的《国富论》中以制针业为例说明了以下哪点的好处<br>
                <input type="radio" name="q4" value="*">A.劳动分工<br>
                <input type="radio" name="q4" value="0">B.计件工资<br>
                <input type="radio" name="q4" value="0">C.成本控制<br>
                <input type="radio" name="q4" value="0">D.计划职能<br>
                <br>
                5.对计划工作进行定期修订的方法被称为<br>
                <input type="radio" name="q5" value="0">A.平衡法<br>
                <input type="radio" name="q5" value="0">B.运筹法<br>
                <input type="radio" name="q5" value="0">C.投入产出法<br>
                <input type="radio" name="q5" value="*">D.滚动计划法<br>
                <br>
                6.通过管理提高效益，需要一个时间过程，这表明管理学是一门<br>
                <input type="radio" name="q6" value="0">A应用性学科<br>
                <input type="radio" name="q6" value="0">B.硬科学<br>
                <input type="radio" name="q6" value="*">C..软科学<br>
                <input type="radio" name="q6" value="0">D.定量化学科<br>
                <br>
                7.汽车生产线上的装配工人，需遵守统一的操作规程，有协作要求，强调团队精神，需一定自主权。因此，最好采用<br>
                <input type="radio" name="q7" value="0">A.剥削式的集权领导<br>
                <input type="radio" name="q7" value="*">B.仁慈式的集权领导<br>
                <input type="radio" name="q7" value="0">C.协商式的民主领导<br>
                <input type="radio" name="q7" value="0">D.参与式的民主管理<br>
                <br>
                8.在决策过程中，根据决策目标的要求寻找实现目标的途径是<br>
                <input type="radio" name="q8" value="0">A.发现问题<br>
                <input type="radio" name="q8" value="*">B.设计方案<br>
                <input type="radio" name="q8" value="0">C.选择方案<br>
                <input type="radio" name="q8" value="0">D.实施决策<br>
                <br>
                9.科学管理中最能体现权力下放的原理是<br>
                <input type="radio" name="q9" value="0">A.差别计件工资<br>
                <input type="radio" name="q9" value="0">B.职能原理<br>
                <input type="radio" name="q9" value="*">C.例外原理<br>
                <input type="radio" name="q9" value="0">D.工时研究<br>
                <br>
                10.某企业要进行一项投资项目决策，项目产品未来五年可能出现，市场好.中.差三种状态，但无法预测各壮态分别出现的可能性大小。这种决策属于<br>
                <input type="radio" name="q10" value="0">A.确定性决策<br>
                <input type="radio" name="q10" value="0">B.程序化决策<br>
                <input type="radio" name="q10" value="*">C.不确定性决策<br>
                <input type="radio" name="q10" value="0">D.风险决策<br>
                <br>
                11.学习型组织的核心是<br>
                <input type="radio" name="q11" value="0">A.改进心智模式<br>
                <input type="radio" name="q11" value="*">B.系统思考<br>
                <input type="radio" name="q11" value="0">C.勾画愿景<br>
                <input type="radio" name="q11" value="0">D.团队学习<br>
                <br>
                12.以下哪种情况有最利于促进集权制<br>
                <input type="radio" name="q12" value="0">A.由多个公司合并组建的新公司<br>
                <input type="radio" name="q12" value="0">B.公司有大量高素质管理者<br>
                <input type="radio" name="q12" value="0">C.公司规模大业务多<br>
                <input type="radio" name="q12" value="*">D.公司管理信息化水平高<br>
                <br>
                13.根据领导的生命周期理论，对于有能力无意愿的员工，应该采用的领导方式是:<br>
                <input type="radio" name="q13" value="0">A.高工作高关系<br>
                <input type="radio" name="q13" value="0">B.高工作低关系<br>
                <input type="radio" name="q13" value="0">C.低工作低关系<br>
                <input type="radio" name="q13" value="*">D.低工作高关系<br>
                <br>
                14.一天，渔夫看到一条蛇咬青蛙，渔夫不忍救了青蛙。但渔夫又为蛇失去食物而难过，于是就取出一点食物给蛇吃。蛇高兴地游走了。几分种后，那条蛇又咬了两只青蛙回到渔夫的面前。这显然不是渔夫要的结果。这个故事说明:<br>
                <input type="radio" name="q14" value="0">A.激励影响绩效<br>
                <input type="radio" name="q14" value="0">B.激励要明确目标<br>
                <input type="radio" name="q14" value="*">C.激励的强度要适中<br>
                <input type="radio" name="q14" value="0">D.激励要切中人的最需<br>
                <br>
                15.就客观条件，尤其是对管理者需要的信息量和可靠性而言，要求最高的控制类型是<br>
                <input type="radio" name="q15" value="0">A.同期控制<br>
                <input type="radio" name="q15" value="0">B.反馈控制<br>
                <input type="radio" name="q15" value="*">C.前馈控制<br>
                <input type="radio" name="q15" value="0">D.集中控制<br>
                <br>
                二、不定项选题<br>
                1.建立在权威与服从关系基础上，表现为一种权力支配关系的是<br>
                <input type="checkbox" name="q16" value="0">A.法律手段<br>
                <input type="checkbox" name="q16" value="0">B.经济手段<br>
                <input type="checkbox" name="q16" value="*">C.行政手段<br>
                <input type="checkbox" name="q16" value="0">D.思想教育手段<br>
                <br>
                2.职能型组织结构形式的优点是实现了<br>
                <input type="checkbox" name="q17" value="0">A.管理现代化<br>
                <input type="checkbox" name="q17" value="*">B.管理专业化<br>
                <input type="checkbox" name="q17" value="0">C.统一指挥<br>
                <input type="checkbox" name="q17" value="0">D.统一领导<br>
                <br>
                3.在现代管理学中，管理人员对当前的实际工作是否符合计划而进行测定并促使组织目标实现的过程，被称为<br>
                <input type="checkbox" name="q18" value="0">A.领导<br>
                <input type="checkbox" name="q18" value="0">B.组织<br>
                <input type="checkbox" name="q18" value="0">C.创新<br>
                <input type="checkbox" name="q18" value="*">D.控制<br>
                <br>
                4.具有“压制个人目标，使组织目标凌驾于个人目标之上”特征的是<br>
                <input type="checkbox" name="q19" value="*">A.传统管理<br>
                <input type="checkbox" name="q19" value="0">B.现代管理<br>
                <input type="checkbox" name="q19" value="0">C.目标管理<br>
                <input type="checkbox" name="q19" value="0">D.组织管理<br>
                <br>
                5.以法约尔的观点，劳动分工原则<br>
                <input type="checkbox" name="q20" value="0">A.仅适用于技术工作<br>
                <input type="checkbox" name="q20" value="*">B.不仅适用于技术工作也适用于管理工作<br>
                <input type="checkbox" name="q20" value="0">C.分工越细越好<br>
                <input type="checkbox" name="q20" value="0">D.分工越粗越好<br>
            </strong>
            </p>
            <fieldset>
                <input type="hidden" name="sscore" value="" id="ggmg">
                <input type="hidden" name="stime" value="" id="ggtime">
                <input type="submit" value="提交">
            </fieldset>
            <br>
        </form>
    </div>
   <div class="center">
        <div class="text"><a href="../XiaBee_files/connect.asp">查看排名</a></div>
   </div>
    <div class="button">
        <div class="gradual"></div>
    </div>

    <div class="center">
            <div class="text"><a href="../index.html">BACK TO INDEX</a></div>
    </div>
    <div class="button">
            <div class="gradual"></div>
    </div>


    
</body>
</html>