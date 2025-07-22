express = require("express");

eobj = express();

port = 5100;

function MarvellousWelcomeMessage()
{
    console.log("Marvellous Server is ON at port 5100...");
}

eobj.listen(port,MarvellousWelcomeMessage);

function MarvellousAcceptRequest(req,res)
{
    res.send("Marvellous Server Connection is succesful...");
}

eobj.get('/',MarvellousAcceptRequest);

function MarvellousBatches(req,res)
{
    res.send("We have PPA, Angular, Python, LB");
}

eobj.get('/Batches', MarvellousBatches);

function MarvellousLocation(req,res)
{
    res.send("Location of Marvellous is Kothrud Pune")
}

eobj.get('/Location', MarvellousLocation);

function MarvellousBatchDetails(req,res)
{
    res.json({"Batch" : "PPA", "Fess" : 21000, "Duration" : "3 Months"});
}

eobj.get('/Getbatchdetails', MarvellousBatchDetails);