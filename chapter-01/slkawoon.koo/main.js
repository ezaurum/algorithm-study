// 호너법
// f(x) = a(n)x^n + a(n-1)x^(n-1) + ... + a(1)x + a(0)

// 이건 그냥 문제를 풀어서 놓기
// function HornerMethod (x, a) {
//   var result = 0;
//   result = (((a[4]*x + a[3])*x + a[2])*x + a[1])*x + a[0];
  
//   console.log(result);
//   return result;
// }

// 이건 방정식 그대로 사용
// function Polynomial (x, a) {
//   var result = 0;
//   for(var i = 0; i < a.length; i++) {
//     result += (a[i] * Math.pow(x, i));
//   }
//   console.log(result);
//   return result;
// }

// 이건 호너법
var _coefficient = [1, 2, 3, 4, 5]; // 계수

function selfHornerFunc(x, a) {
  var i = a.length - 1;
  var Y = a[i]*x + a[i - 1]; 

  for(i; i > 1; i--) {
    Y = Y*x+a[i - 2]; // 점화식
    console.log(Y, i);
  }

  return Y;
}
selfHornerFunc(1, _coefficient);