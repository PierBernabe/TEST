//_ = require('lodash')
var tab = [{stephane:1}, {rsercer:2}, {tristan:1}]

function rsercer1() {
  for(i=0; i < tab.length; i++) {
    console.log("tabImperatif", tab[i])
  }
}

function rsercer2() {
  // Utilisez la fonction forEach sur tab
  console.log("rsercer2, il faut utiliser forEach")
}

function rsercer3() {
  // Utilisez la bibliothèque lodash
  console.log("rsercer3, il faut utiliser lodash")
}

rsercer1();
rsercer2();
rsercer3();
