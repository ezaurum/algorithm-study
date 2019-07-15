const combination = require('./combination');

function pascal(n) {
  for (let i = 0; i <= n; i++) {
    let tabs = '';
    for (let k = n - i; k > -1; k--) {
      tabs += '\t';
    }
    let nums = '';
    for (let j = 0; j <= i; j++) {
      nums += combination(i, j, true) + '\t\t';
    }
    console.log(tabs + nums);
  }
}

module.exports = pascal;
