
Number.prototype.format = function(slen,dlen) { // slen: space len, dlen: digit len
    
    let thisNumber = this.toString();

    //default slen , dlen - 걍 정함
    slen = slen || 8;
    dlen = dlen || 6;

    if(thisNumber.length>slen){
        thisNumber = thisNumber.substr(0,slen);
    }
    if(thisNumber.length>dlen){
        thisNumber = thisNumber.substr(0,dlen);
    }
    if(dlen>slen){
        thisNumber = thisNumber.substr(0,slen-1);
    }

    let resultNumber='';
    for(i=0;i<slen-thisNumber.length;i++)
        resultNumber = resultNumber + ' ';
    resultNumber = resultNumber + thisNumber;

    return resultNumber;
}


let rNumber = 13; // 초기 숫자
function randomNumber () {
    rNumber = (109* rNumber +1021) %32768;
    return rNumber;
}

let arrSize = 100;
let firstRndNumber;
let rndNum;
let range;
let resultStr = '';
for(let i=0;i<arrSize;i++){
    rndNum = randomNumber().format(10,6);
    if(i == 0){
        firstRndNumber = rndNum;
    }
    if(i>0 && i%10 ==0){
        resultStr = resultStr + '\n';
    }
    if(firstRndNumber == rndNum && i >0) range = i;
    resultStr = resultStr + rndNum;
}


console.log(resultStr);
//console.log('########### range size: ' + range );

