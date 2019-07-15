/* 
    f(1) = 1, f(2) = 1, f(n) = f(n-1) + f(n-2)
*/
function fibonacci(n) {
  console.log(1);
  if (n === 1) {
    return 1;
  }
  let f1 = 1;
  console.log(' ' + 1);
  if (n === 2) {
    return 1;
  }

  let f2 = 1;
  let result;
  for (let i = 3; i <= n; i++) {
    result = f1 + f2;
    f2 = f1;
    f1 = result;
    console.log(' ' + result);
  }

  return result;
}

module.exports = fibonacci;
