function sfrenot1() {
  console.log("rsercer1 Je suis une fonction à callback");
  console.log("rsercer1 Je ne suis pas une fonction à callback");
  return "rsercer";
}

function rsercer2(a, b) {
  console.log("rsercer2 je suis une fonction à callback");
  console.log("rsercer2 je ne suis pas une fonction à callback");
  return b();
}

function rsercer3(a, b) {
  console.log("rsercer3 je suis une fonction à callback");
  console.log("rsercer3 je ne suis pas une fonction à callback")
  return b;
}

console.log(rsercer1(1, sfrenot1));
console.log(rsercer2(1, sfrenot1));
console.log(rsercer3(1, sfrenot1));
