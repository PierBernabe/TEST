_ = require('lodash')
var tab = [{stephane:1}, {pbernarbe:2}, {tristan:1}]

function pbernarbe1() {
  for(i=0; i < tab.length; i++) {
    console.log("tabImperatif", tab[i])
  }
}

function pbernarbe2() {
  // Utilisez la fonction forEach sur tab
  console.log("pbernarbe2, il faut utiliser forEach")
  tab.forEach((e) => {
    console.log(e);
  });
}

function pbernarbe3() {
  // Utilisez la méthode map de la bibliothèque lodash
  console.log("pbernarbe3, il faut utiliser lodash")
   _.forEach(tab, (e) => {
     console.log(e);
  })
}

pbernarbe1();
pbernarbe2();
pbernarbe3();
