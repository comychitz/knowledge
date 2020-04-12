package main

//
// simple http web app example
//

import "net/http"

func handlerFunc(w http.ResponseWriter, r *http.Request) {
    w.Write([]byte("Yoooooo"))
}

func main() {
    // setup handler
    http.HandleFunc("/", handlerFunc)

    // run server 
    http.ListenAndServe(":8000", nil)

    // to view, go to locahost:8000 in your browser
}
