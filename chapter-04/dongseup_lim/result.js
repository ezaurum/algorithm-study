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

console.log('-------------------------------------------');


function fib2(num) {
  let arr = [1, 2];

  for (let i = 2; i <= num; i++) {
    arr.push(arr[i - 1] + arr[i - 2]);
  }

  return `${arr}`;
}

console.log(fib2(10)); 

console.log('-------------------------------------------');

