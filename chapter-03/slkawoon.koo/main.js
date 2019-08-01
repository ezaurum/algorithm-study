const arr = [29, 5, 37, 20, 1, 10, 17, 2];
// 기본 교환법 거품정렬
const main = (arr) => {
  var result = [];
  for(var i = 0; i < arr.length - 1; i++) {
    for(var j = arr.length - 1; j > i; j--) {
      if(arr[j] < arr[j-1]) {
        result = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = result;
      }
    } 
  }
  console.log(arr);
};

// main(arr);




//이분 탐색

const num = [2, 3, 7, 11, 31, 50, 55, 70, 77, 80];

const searchByDivine = (key) => {
  let low = 0;
  let high = 9;
  let result = 0;

  while (low <= high) {
    result = Math.round((low + high) / 2);
    if(num[result] === key) {
      console.log((result + 1) + '번째');
      break;
    } else if (num[result] < key) {
      low = result + 1;
    } else {
      high  = result - 1;
    }
  }
}

searchByDivine(50);