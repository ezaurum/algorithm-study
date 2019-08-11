// 재귀함수를 이용해 팩토리얼 구하기

function factorial (n) {
  if (n === 0) return 1;
  else { 
    return n * factorial(n - 1);
  }
}

// console.log(factorial(1));

// 재귀함수 이용해 피보나치 수열 구하기

function main(n) {
  if (n === 1 || n === 2) return 1;
  else {
    return main(n - 1) + main(n - 2);
  }
}

function fibonacci(n) {
  for (let i = 1; i < 20; i++) {
    console.log(main(i));
  }
}

fibonacci(5);
