const osu = require('node-osu');
// https://stackoverflow.com/questions/6831918/node-js-read-a-text-file-into-an-array-each-line-an-item-in-the-array



var interval = 10 * 1000;
var fs = require('fs');
var beatmap_ids = fs.readFileSync('o.txt').toString().split('\n');
// for (var i = 0; i < 5; i++) {
//     setTimeout( function (i) {
//         osuApi.getScores({b: beatmap_ids[i]}).then(scores => {

//             // fs.appendFile('topScores.txt', "user_id: " + scores[i].user.id + " beatmap_id: " + scores[i].beatmapId + " pp: " + scores[i].pp + " mods: " + scores[i].mods + "\n", function(){});
//         });
//     ), interval * i, i);
// }

function pauseloop () {
    setTimeout( function() {
        
    })
}