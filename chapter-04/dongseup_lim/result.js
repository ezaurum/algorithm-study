// 4장 피보나치(재귀)
function fib(num) {
  if (num == 1 || num == 2) {
      return num;
  } else {
      return fib(num - 1) + fib(num - 2);
  }
}

for (let n = 1; n <= 20; n++) {
  console.log(`${n} : ${fib(n)}`);
}

//////////////////////////////////////////////////////////////////////


function fib2(num) {
  let arr = [1, 2];

  for (let i = 2; i <= num; i++) {
    arr.push(arr[i - 1] + arr[i - 2]);
  }

  return `${arr}`;
}

console.log(fib2(10)); 

//////////////////////////////////////////////////////////////////////

// codility 1 - binaryGap

function solution(N) { 
  var number = N; 
  var binary = '';
  var counter = -1;
  var max = 0;

  while(number > 0) {
    var digit = number % 2;
    
    if(digit === 1) {
      if (counter > max) {
        max = counter;
      }
      counter = 0;
    } else if(counter >= 0) {
      counter++;
    }

    binary = '' + digit + binary
    number = parseInt(number / 2);
  }
  console.log('number, binary:', number, binary);
  return max
}

solution(10);