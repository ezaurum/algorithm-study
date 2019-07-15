// n, r >= 0, n >= r

function combination(n, r, noconsole = false) {
  let result = 1;
  if (!noconsole) {
    console.log(n + 'C0' + ': ' + result);
  }
  for (let i = 1; i <= r; i++) {
    const mul = (n - i + 1) / i;
    result *= mul;
    if (!noconsole) {
      console.log(n + 'C' + i + ': ' + result);
    }
  }
  return result;
}

module.exports = combination;
