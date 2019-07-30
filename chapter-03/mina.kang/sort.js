
const CUTIL = require('./utils.js');

exports.selectionSort00 = function (dataArr) {

    const copedArr = [...dataArr]; //참조말고 배열 복사!
    let cnt = 1;

    let min;
    let p1,p2;
    for(let i=0;i<copedArr.length;i++){
      for(let j=i+1;j<copedArr.length;j++){
          if(copedArr[j] < copedArr[i]) CUTIL.swap(copedArr, i, j,cnt++); // arr[i]와 비교하여 그때그때 바꾼다. cf . selectionSort 와 비교
      }
    }
    console.log('###### selectionSort00 result : ', copedArr,'\n');
 }

exports.selectionSort = function (dataArr) {

   const copedArr = [...dataArr]; //참조말고 배열 복사!
   let cnt = 1;
   let min;
   let p1,p2;
   for(let i=0;i<copedArr.length;i++){
     min = copedArr[i];
     
     for(let j=i+1;j<copedArr.length;j++){
         if(copedArr[j] < min) {
            min = copedArr[j]; 
            p1 = j; // arr[i] 와 바꿀 부분을 표시해놓고 한바퀴 돈 다음에  swap.
         } 
     }
     CUTIL.swap(copedArr, i, p1, cnt++);
   }
   console.log('###### selectionSort result : ', copedArr,'\n');
}

exports.bubbleSort = function (dataArr){
    const copedArr = [...dataArr];
    let cnt = 0;
    for(let pass=1;pass<copedArr.length;pass++){
        for(let i=copedArr.length-1;i>pass-1;i--){
            if(copedArr[i] < copedArr[i-1]) CUTIL.swap(copedArr,i, i-1,cnt++);
        }
    }

    console.log('###### bubbleSort result : ', copedArr,'\n');
}

exports.shakerSort = function(dataArr) {
    const copedArr = [...dataArr];
    let cnt = 1;
    let left = 0; 
    let right = copedArr.length-1;
    let shift;
    while(left<right){
        for(let i=left;i<right;i++){
            if(copedArr[i] >copedArr[i+1]){
                CUTIL.swap(copedArr, i, i+1,cnt++ );
                shift = i;
            }
        }
        right = shift;;
        for(let i=right;i>left;i--){
            if(copedArr[i-1] > copedArr[i] ){
                CUTIL.swap(copedArr, i-1, i,cnt++);
                shift = i;
            }
        }
        left = shift;
    }
    console.log('###### shakerSort result : ', copedArr,'\n');
}


