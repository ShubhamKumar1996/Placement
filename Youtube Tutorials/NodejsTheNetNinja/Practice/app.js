let fs = require('fs');

fs.unlink("./stuff/writeMe.txt", function(){
    fs.rmdirSync("stuff");
});