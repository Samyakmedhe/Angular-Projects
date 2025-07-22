const {MongoClient} = require("mongodb");
const URL = "mongodb://localhost:27017";
const client = new MongoClient(URL);

async function GetConnection() 
{
    let result = await client.connect();
    let db = result.db("Marvellous");
    return db.collection("Batches");
}

async function ReadData() 
{
      let data  = await GetConnection();
      data = await data.find().toArray();
      console.log("Data retrived from database : ");
      console.log(data);   
}

async function InsertData() 
{
      let data  = await GetConnection();
      let result = await data.insertOne({
        "Name" : "Python", "Fees" : "22000", "Duration" : "2.5 months"
      });
      if(result.acknowledged)
      {
        console.log("Data inserted succesfully");
      }
}

async function DeleteData() 
{
      let data  = await GetConnection();
      let result = await data.deleteOne({"Name" : "Python"});
      if(result.acknowledged)
      {
        console.log("Data deleted succesfully");
      }
}

async function UpdateData() 
{
      let data  = await GetConnection();
      let result = await data.updateOne({"Name" : "LB"}, {$set : {"Fees" : "25000"}});
      if(result.acknowledged)
      {
        console.log("Data updated succesfully");
      }
}

function main()
{
    let ret;

    ret = GetConnection();
    console.log(ret);
    console.log("Database connection is succesful");

    //ReadData();
    //InsertData();
    //DeleteData();
    UpdateData();
}

main()