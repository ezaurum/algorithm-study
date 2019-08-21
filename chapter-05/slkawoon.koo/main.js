// 정수 배열과 타겟 숫자가 주어지면, 합이 타겟값이 되는 두 원소의 인덱스를 찾으시오.
// 단 시간 복잡도는 O(nlogn)
// 예) Input: [2, 5, 6, 1, 10], 타겟 8
// Output: [0, 2]
// 배열[0] + 배열[2] = 8

const main = (Arr, num) => {
  let result = [];
  for(let i = 0; i < Arr.length; i++) {
    for(let j = 0; i < Arr.length; j++) {
      if(num === Arr[i] + Arr[j]) {
        result.push(i,j);
        return result;
      }
    }
  }
};

// Given the triangle of consecutive odd numbers:
// 1
// 3 5
// 7 9 11
// 13 15 17 19
// 21 23 25 27 29
// Calculate the row sums of this triangle from the row index (starting at index 1)
// e.g.:
// row_sum_odd_numbers(1); # 1
// row_sum_odd_numbers(2); # 3 + 5 = 8

const row_sum_odd_numbers = (n) => {
  let initValue = n * n + n + 1;
  const length = n + 1;
  let result = 0;
  
  for(let i = 0; i < length; i++) {
    result += (initValue + i * 2);
  }
  console.log(result);
};

row_sum_odd_numbers(4);