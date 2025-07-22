express = require("express");

eobj = express();

port = 5100;

function MarvellousWelcomeMessage()
{
    console.log("Marvellous Server is On at port 5100...");
}

eobj.listen(port, MarvellousWelcomeMessage);


function MarvellousAcceptRequest(req, res)
{
    res.send("Marvellous Server Connection is succesfull...");
}

eobj.get('/',MarvellousAcceptRequest);


function MarvellousBatches(req,res)
{
    res.send("we have PPA , Angular , Python ,LB");
}

eobj.get('/Batches',MarvellousBatches);


function MarvellousLoacation(req ,res)
{
    res.send("Loaction of Marvellous is Kothrud Pune")
}

eobj.get('/Location', MarvellousLoacation);


function MarvellousBatchesDetails(req,res)
{
    res.json({"Batch" : "PPA" , "Fees" : 21000, "Duration" : "3 Months"});
}

eobj.get('/Getbatchdetails', MarvellousBatchesDetails);
