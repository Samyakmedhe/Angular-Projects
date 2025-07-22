const { response } = require("express");

express = require("express");


eobj = express();
port = 5200;

function listenServer()
{
    console.log("Marvellous server is in Listening mode");
}
eobj.listen(port, listenServer)

function ConnectRoute(req , res)
{
    response.send("Marvellous Server is on ...");
}

eobj.get('/', ConnectRoute);
