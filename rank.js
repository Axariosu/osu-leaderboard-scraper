

// osuApi.getBeatmaps({b: '765567'}).then(beatmaps => {
//     console.log(beatmaps[0]);
// });

// https://medium.freecodecamp.org/the-ultimate-guide-to-web-scraping-with-node-js-daa2027dcd3
// https://stackoverflow.com/questions/3459476/how-to-append-to-a-file-in-node

const rp = require('request-promise');
const fs = require('fs');
const $ = require('cheerio');
var pageNumber = [1, 2];



function writeUsers() {
    console.log("writeUsers\n");
    var stats = fs.statSync("users.txt");
    
    if (stats.size == 0) {
        console.log("writing to users.txt\n");
        for (let i = 0; i < pageNumber.length; i++) {
            const url = "http://osu.ppy.sh/rankings/osu/performance?page=" + pageNumber[i];
            // console.log(pageNumber[i]);
            rp(url) 
            .then(function(html){
                // const test = [];
                // for (var j = 1; j < $('td > div > a', html).length; j += 2) {
                for (var j = 1; j < 201; j += 2) {
                // for (var j = 99; j > 0; j -= 2) {
                    var str = JSON.stringify($('td > div > a', html)[j].attribs);
                    var userpage = str.split('\"');
                    var userid = userpage[3].split('\/');
                    // console.log(userid[4]);
                    fs.appendFileSync("users.txt", userid[4] + "\n", function(){});
                    // test.push($('td > div > a', html)[i].attribs);
                }
                // console.log(test);
            })
            .catch(function(err){
                //handle error
            });
        }
    } else {
        console.log("found non-empty users.txt\n");
        // console.log("removing users.txt\n");
        // fs.writeFileSync("users.txt", '', function(){});
        // writeUsers();
    }
    console.log("size of users.txt: " + stats.size + " bytes\n");
}

function retrieveUsers() {
    console.log("retrieveUsers\n");
    // var contents = fs.readFileSync('users.txt', 'utf8');
    // console.log(contents);
    // var fs1 = require('fs');
    fs.readFile('users.txt', function read(err, data) {
        if (err) throw err;
        // for (var i = 0; i < data.length; i++) {
        //     console.log(data[i]);
        // }
        var users = data.toString('utf8').split('\n');
        console.log(users[0]);
    });
}

function reformatUsers() {
    console.log("reformatUsers\n");
    fs.readFile('users.txt', function read(err, data) {
        if (err) throw err;
        // for (var i = 0; i < data.length; i++) {
        //     console.log(data[i]);
        // }
        var users = data.toString('utf8').split('\n');
        clearUsers();
        var replicates = Math.floor(users.length / 50);
        console.log(replicates);
        var start = replicates - 1;
        while (start > -1) {
            for (var i = 0; i < 50; i++) {
                fs.appendFile('users.txt', users[start*50 + i] + "\n", function(){});
            }
            start--;
        };
    });
}

function clearUsers() {
    console.log("clearUsers\n");
    fs.writeFile('users.txt', '', function (){});
}

writeUsers();
reformatUsers();
retrieveUsers();



