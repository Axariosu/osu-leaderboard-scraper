const osu = require('node-osu');
// https://stackoverflow.com/questions/6831918/node-js-read-a-text-file-into-an-array-each-line-an-item-in-the-array



var fs = require('fs');
var player_ids = fs.readFileSync('users100.txt').toString().split('\n');
for(id in player_ids) {
    // console.log(player_ids[id]);
    osuApi.getUserBest({u: player_ids[id], limit: 100}).then(scores => {
    for (var i = 0; i < 100; i++) {
        fs.appendFile('scores100.txt', "user_id: " + scores[i].user.id + " beatmap_id: " + scores[i].beatmapId + " pp: " + scores[i].pp + " mods: " + scores[i].mods + "\n", function(){});
        // console.log("beatmap_id: " + scores[i].beatmapId + " pp: " + scores[i].pp + "\n")
        }
    })
}