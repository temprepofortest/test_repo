const url = require("url")
const http = require("http")
const fs = require('fs')
const native = require('bindings')('native')

const hostname = '127.0.0.1';
const port = 3001;

var route = {   
  routes : {},
  for: function(path, handler) {
    this.routes[path] = handler 
  } 
}

route.for("/about", function(request, response) {
    fs.readFile('Templates/About.html', function (err, data) {
        response.writeHead(200, {'Content-Type': 'text/html', 'Content-Length': data.length})
        response.write(data)
        response.end()
    }) 
})

route.for("/main", function(request, response) {

    fs.readFile('Templates/FibForm.html', function (err, data) {
        response.writeHead(200, {'Content-Type': 'text/html', 'Content-Length': data.length})
        response.write(data)
        response.end()
    })
})

route.for("/fib", function(request, response) {
    response.writeHead(200, {"Content-Type": "text/plain"})    
    response.write(JSON.stringify({
        number: native.nextNumber()
    }))   
    response.end()  
})

function onRequest(request, response) { 
    var pathname = request.url
    console.log("Request for " + pathname + " received.")
    if (typeof route.routes[pathname] === 'function') {    
        route.routes[pathname](request, response)  
    } else {    
        response.writeHead(404, {"Content-Type": "text/plain"})   
        response.end("404 Not Found") 
    } 
}

http.createServer(onRequest).listen(port, hostname) 
console.log(`Server has started on http://${hostname}:${port}`)