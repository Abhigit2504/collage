const express = require("express");
const mongoose = require("mongoose");
const app = express();

const url =('mongodb://localhost:27017/details',{
   useNewUlrParser:true,useUnifiedTopology:true
},
(err)=>{
   if(err){
       console.log(err)

   }else{
       console.log("connected")
   }
}
)

async function connect(){
     try{
        await mongoose.connect(url)
        console.log("connected to mongoDb");
     }catch(error){
        console.error(error);
     }
}
connect();

app.listen(8000,() =>{console.log("server started in port 3000")});


// const {Mongoclient} =require('mongodb');
// const url ='mongodb://localhost:27017';
// const database = 'details' 

// const client = new Mongoclient(url);
// async function getData(){
//     let result = await client.connect();
//     let db = result.db(database);
//     let collection = db.collection('login');
//     let response = await collection.find({}).toArray()
//     console.log(response);
// }

// getData();