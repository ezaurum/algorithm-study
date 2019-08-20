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

console.log(main([2, 5, 6, 1, 10], 8));