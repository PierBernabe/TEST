function pbernarbe1() {
  //console.log("pbernarbe1 Je suis une fonction à callback");
  console.log("pbernarbe1 Je ne suis pas une fonction à callback");
  return "pbernarbe";
}

function pbernarbe2(a, b) {
  console.log("pbernarbe2 je suis une fonction à callback");
  //console.log("pbernarbe2 je ne suis pas une fonction à callback");
  return b();
}

function pbernarbe3(a, b) {
  //console.log("pbernarbe3 je suis une fonction à callback");
  console.log("pbernarbe3 je ne suis pas une fonction à callback")
  return b;
}

console.log(pbernarbe1(1, pbernarbe1));
console.log(pbernarbe2(1, pbernarbe1));
console.log(pbernarbe3(1, pbernarbe1));
