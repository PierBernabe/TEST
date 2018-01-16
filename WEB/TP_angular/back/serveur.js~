var express = require('express');
var server = express();
server.get('/', function(request, response){
    console.log('MainPage_deliver');
    response.sendfile('/home/pbernarbe/WEB/TP_angular/front/page1.html');
});

server.use('/lib', express.static('/home/pbernarbe/WEB/TP_angular/node_modules')//permet 		d'acceder à un dossier depuis le net
);

server.get('/test', function(request, response){
    response.sendfile('/home/pbernarbe/WEB/TP_angular/test.json')
});

server.listen(3000);
