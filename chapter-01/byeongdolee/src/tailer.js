/* 
    e^x to tailer
    x = 1, e => 2.71828182845904523536028747135266249775724709369995...
                2.7182818011463845 n = 10
                2.7182818284590455 n = 100
                2.7182818284590455 n = 1000 100이랑 1000이랑 똑같네
*/
function tailer(x, n) {
  let result = 1;
  console.log('e^0: 1');

  let sum = 1;
  for (let i = 1; i <= n; i++) {
    result = (result * x) / i;
    sum += result;
    console.log('e^' + x + '(n = ' + i + ') = ' + sum);
  }
}

module.exports = tailer;
