
exports.util1 = function() {
    console.log('util1 import test');
}


exports.swap = function(arr, i, j, cnt){
    let tempVar = arr[i];
    arr[i] = arr[j];
    arr[j] = tempVar;
    console.log(` ${cnt} -- ` + arr);
}

exports.myRand = function(from, to, cnt){
    let arr = new Array();

    for(let i=0;i<=cnt;i++){
        arr.push( Math.floor(Math.random()*(to-from)) + from );
    }
    return arr;
}