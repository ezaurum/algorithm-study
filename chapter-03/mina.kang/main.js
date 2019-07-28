const SORT = require('./sort.js');
const CUTIL = require('./utils.js');


//let tData = [80,41,35,90,40,20];
let tData = CUTIL.myRand(1,100,15);
console.log('#### rowData: ' , tData.join(','), '\n\n\n');


SORT.selectionSort00(tData);
SORT.selectionSort(tData);
SORT.bubbleSort(tData);
SORT.shakerSort(tData);


let tData2 = [3,5,6,9,2,7,8,10,4];
console.log('#### rowData: ' , tData2, '\n\n\n');
SORT.bubbleSort(tData2);
SORT.shakerSort(tData2);
