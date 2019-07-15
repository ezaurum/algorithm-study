/* 
    계수 배열을 입력으로 받음
    차수 내림차순으로 입력
    ex) y = 3x^3 + 2x + 1 인 경우 [3, 0 ,2, 1]을 인풋으로!
*/
function horner(x, coefficients) {
  let result = 0;
  for (let i = 0; i < coefficients.length; i++) {
    result = result * x + coefficients[i];
    console.log('f(' + i + ') = ' + result);
  }
  return result;
}

module.exports = horner;
