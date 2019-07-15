/* 
    f(x) = x^n
    = x * x^(n-1)
*/
function power(x, n) {
  let result = 1;
  console.log(x + '^0 = 1');
  for (let i = 1; i <= n; i++) {
    result *= x;
    console.log(x + '^' + i + '= ' + result);
  }
  return result;
}

module.exports = power;
