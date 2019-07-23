// X[n] = (A*X[n-1] + C) % M
const randomNumber = (A, C, M) => {
  var rndnum = [13];
  for(var i = 0; i < 100; i++) {
    rndnum = (A*rndnum + C) % M;
    console.log(rndnum);
  }
  return rndnum;
};

randomNumber(109, 1021, 32768);