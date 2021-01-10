<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="gbk">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
    <script src="score.js"></script>
</head>
<body>
    <%
    set conn=Server.CreateObject("ADODB.Connection")
    conn.Provider="Microsoft.Jet.OLEDB.4.0"
    conn.Open(Server.Mappath("score.mdb"))
    
    set rs= Server.CreateObject("ADODB.recordset")
    rs.Open "score",conn, 2, 3
    username= Request ("username")
    sgsstime = Request("stime")
    
    score= int(Request("sscore"))
    rs.AddNew
    rs("s_name") = username
    rs("s_score") = score
    rs("s_time") = sgsstime + " seconds"
    
    rs.Update
    rs.close
    conn.close

    %>
    

</body>
</html>