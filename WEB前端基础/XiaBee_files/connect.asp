<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Scores</title>
    <link type="text/css" rel="stylesheet" href="../XiaBee_files/default.css">
</head>
<body class="background">
        
        <div class="button">
                <div class="center">
                        <div class="text">All Results</a></div>
                </div>
                <div class="gradual"></div>
        </div>
        <%
        set conn=Server.CreateObject("ADODB.Connection")
        conn.Provider="Microsoft.Jet.OLEDB.4.0"
        conn.Open(Server.Mappath("score.mdb"))
        set rs = Server.CreateObject("ADODB.recordset")
        sql="SELECT s_name,s_score,s_time FROM score order by s_score desc, s_time asc;"
        rs.Open sql, conn

        %>
        
        <table border="1" width="100%" bgcolor="#fff5ee">
        <tr>

       
        <%for each x in rs.Fields
            response.write("<th align='left' bgcolor='#b0c4de'>" & x.name & "</th>")
        next%>
        </tr>
        <%do until rs.EOF%>
            <tr>
            <%for each x in rs.Fields%>
                <td><%Response.Write(x.value)%></td>
            <%next
            rs.MoveNext%>
            </tr>
        <%loop
        rs.close
        %>
        <%
        conn.close
        %>
</body>
</html>