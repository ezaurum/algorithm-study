/* 
    f(x) = x!
    = x * (x-1)!
    0! = 1
*/
function factorial(x) {
  let result = 1;
  console.log('0! = 1');
  if (x === 0) {
    return result;
  }
  for (let i = 1; i <= x; i++) {
    result *= i;
    console.log(i + '! = ' + result);
  }
  return result;
}

module.exports = factorial;
