const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const _ = require("lodash");


app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));
app.set("view engine", "ejs");

//DB
const mongoose = require("mongoose");

mongoose.connect("mongodb+srv://admin0:test123@cluster0.quaorah.mongodb.net/todoDB");

const itemSchema = {
  name: String,
};

const item = mongoose.model("item", itemSchema);

//inserting the items
const item1 = new item({
  name: "Welcome to your todolist!",
});

const item2 = new item({
  name: "Press + to add new task.",
});

const item3 = new item({
  name: "<== Press here to delete an item.",
});

const defaultitems = [item1, item2, item3];

const listSchema = {
  name: String,
  items: [itemSchema],
};

const list = mongoose.model("list", listSchema);

// item.insertMany(defaultitems,function(err){
//   if(err){
//     console.log(err);
//   }
//   else{
//     console.log("Successfully inserted");
//   }
// });

// let tasks = [];
// let workTasks = []

app.get("/", (req, res) => {
  item.find({}, function (err, founditems) {
    if (founditems.length === 0) {
      item.insertMany(defaultitems, function (err) {
        if (err) {
          console.log(err);
        }
        res.redirect("/");
      });
    } else {
      res.render("list", { dayname: "Today", addedtasks: founditems });
    }
  });
});
app.post("/", (req, res) => {
  let task = req.body.newtask;
  let listName = req.body.list;
  listName = listName.replace(/\s+/g, "").toLowerCase();

  const newitem = new item({
    name: task,
  });

  if (listName === "today") {
    newitem.save();
    res.redirect("/");
  } else {
    list.findOne({ name: listName }, function (err, foundList) {
      foundList.items.push(newitem);
      foundList.save();
      res.redirect("/" + listName);
    });
  }
});

app.post("/remove", (req, res) => {
  let id = req.body.checkbox;
  let listName = req.body.listName;
  listName = listName.replace(/\s+/g, "").toLowerCase();


  if(listName==="today"){
    item.findByIdAndDelete(id, function (err) {
      if (err) {
        console.log(err);
      } else {
        res.redirect("/");
      }
    });
  }
  else{
    list.findOneAndUpdate({name:listName},{$pull:{items :{_id:id}}},function(err,foundList){
      if(!err){
        res.redirect("/"+listName);
      }
    })
  }

 
});

app.get("/:customListName", (req, res) => {
  const customListName = (req.params.customListName) ;

  list.findOne({ name: customListName }, function (err, foundlist) {
    if (!err) {
      if (!foundlist) {
        // create a new list
        const List = new list({
          name: customListName,
          items: defaultitems,
        });
        List.save();
        res.redirect("/" + customListName);
      } else {
        // Show the list
        res.render("list", {
          dayname: foundlist.name,
          addedtasks: foundlist.items,
        });
      }
    }
  });

  // let temp = "Work";
  // res.render("list", { dayname: temp, addedtasks: workTasks });
});

app.listen(3000, () => {
  console.log("the server is up and running");
});
