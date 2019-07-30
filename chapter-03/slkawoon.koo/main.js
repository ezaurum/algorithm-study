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

main(arr);