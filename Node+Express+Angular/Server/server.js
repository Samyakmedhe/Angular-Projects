express = require("express")

eobj = express();

port = 5100;

function MarvelousWelcome()
{   
    console.log("Marvellous server in ON ..");
}

eobj.listen(port, MarvelousWelcome);

function MarvellousGet(req , res)
{
    res.send("Marvellous server is Runing ");
}
eobj.get('/',MarvellousGet)

function MarvelousGetBatches(req , res)
{
    res.json({"Batch" : "PPA" , "Fees": 21000 , "Duration" : "3 months"});
}

eobj.get('/getBatches',MarvelousGetBatches);


eobj.use((req , res , next)=> { 
    res.header("Access-Control-Allow-Origin",
        "http://localhost:4200/"
    );
    
    res.header("Access-Control-Allow-Headers","Origin,X-Requested_with,Content_Type,Accept");

    next();

})